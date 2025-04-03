# 🧠 SmartTaskManager
***Projekt jest w trakcie planowania także jego założenia i funkcje mogą (90%) ulec zmianie. Read.me w wersji wstępnej***

**Inteligentny menedżer zadań w C++ z wykrywaniem anomalii**

---

## 📌 Opis projektu

SmartTaskManager to konsolowa aplikacja napisana w języku C++20, która symuluje działanie menedżera zadań systemu operacyjnego. Każdy proces działa jako osobny wątek, generując sztuczne obciążenie CPU i RAM. System analizuje dane w czasie rzeczywistym i wykrywa anomalie w działaniu procesów.

Projekt powstał w celu ćwiczenia:
- programowania współbieżnego (wątki, synchronizacja)
- zarządzania pamięcią (wskaźniki, smart pointers)
- przetwarzania danych w czasie rzeczywistym
- podstawowej sztucznej inteligencji (heurystyki, wykrywanie outlierów)

---

## 🧱 Technologie, które chciałbym aby były użyte

- **C++20**
- Wątki: `std::thread`, `std::jthread`, `mutex`, `condition_variable`
- Wskaźniki: `std::unique_ptr`, `std::shared_ptr`
- Anomaly detection: proste heurystyki / reguły (możliwość rozszerzenia o AI)
- Opcjonalnie: Python (komunikacja z modelem ML)
- Kompilator: `g++` / `clang++` / MSVC
- Build system: `CMake`

---

## 🔍 Funkcje

- ✅ Symulacja wielu procesów jako niezależne wątki
- ✅ Dynamiczne zużycie CPU i RAM
- ✅ Rejestrowanie metryk per proces (rolling window)
- ✅ Wykrywanie anomalii (np. nagłe skoki CPU, zbyt duże zużycie RAM)
- ✅ Reakcja na anomalie (np. oznaczenie, zatrzymanie procesu)
- ⏳ (W planach) Uczenie maszynowe do detekcji anomalii
- ⏳ (W planach) Prosty interfejs terminalowy

---

## 👨‍💻 Autor

Projekt tworzony w celach rozwoju własnego 🎓

Jemdrek03
