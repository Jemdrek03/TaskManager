#include "process.h"

#include <utility>

std::mutex outputCrt;

// Constructor
Process::Process(int id, std::string name, int type)
        : id(id), name(std::move(name)), type(type), running(false), cpuUsage(0.0), ramUsage(0.0) {
    startTime = std::chrono::steady_clock::now();
}
// Up there (name(std::move(name))) we move the parameter 'name' into the member variable to avoid copying.
// This takes advantage of move semantics for efficiency, especially useful for heavier objects like std::string.
// After the move, the original 'name' parameter is in a valid but unspecified state.


// Destructor (thanks to smart pointers, it is automatically called)
Process::~Process() {
    stop();
    if(worker.joinable())
        worker.join();
}

void Process::join() {
    if (worker.joinable()) {
        worker.join();
    }
}

void Process::start(){
    running = true;
    worker = std::thread(&Process::run, this);
}

void Process::stop(){
    running = false;
}

void Process::run(){
    std::default_random_engine generator(std::random_device{}());
    std::uniform_real_distribution<double> cpuDist(10.0, 100.0);
    std::uniform_real_distribution<double> ramDist(10.0, 120.0);

    std::vector<int> ramDummy;

    while (running) {
        switch(type){
            // "Regular program"
            case 1:
                // Simulate CPU and RAM usage
                cpuUsage = cpuDist(generator);
                ramUsage = ramDist(generator);

                // RAM simulation - dynamically allocate a certain amount of memory
                ramDummy.resize(static_cast<size_t>(ramUsage * 1000)); // RAM value in KB

                // Fake CPU load
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));

                // Console output with critical section
                outputCrt.lock();
                std::cout << "[Process " << Process::getId() << "] CPU: " << Process::getCpuUsage() << "% | RAM: " << Process::getRamUsage() << "MB\n";
                outputCrt.unlock();
                break;
                // Program with anomaly
            case 2:
                break;
        }
    }

    // Clear allocated memory after stopping the process
    ramDummy.clear();
    ramDummy.shrink_to_fit();

    // Critical section for output
    outputCrt.lock();
    std::cout << "Process [" << Process::getId() << "] (" << Process::getName() << ") stopped." << std::endl;
    outputCrt.unlock();
}

// Getters
double Process::getCpuUsage() const {
    return cpuUsage;
}

double Process::getRamUsage() const {
    return ramUsage;
}

int Process::getId() const {
    return id;
}

std::string Process::getName() const {
    return name;
}
