#include <iostream>
#include <memory>
#include <thread>
#include "process.h"

int main() {
    std::cout << "=== SmartTaskManager: Test Process ===" << std::endl;

    // Create a process as a smart pointer
    // A nice option because once we exit main's scope, shared_ptr automatically calls the destructor
    auto process = std::make_shared<Process>(1, "TestProcess", 1);

    // Start the process
    process->start();

    // Wait a few seconds to observe its behavior
    std::this_thread::sleep_for(std::chrono::seconds(10));

    // Stop the process
    process->stop();

    // Give it a moment to safely finish the thread
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "=== Process stopped ===" << std::endl;
    return 0;
}

