# F1 Lap Time Anomaly Detector

This program loads F1 lap time data and lets you compare linear vs quadratic probing hash tables. It also does some basic anomaly detection to flag weird laps (really slow or really fast compared to the driver's average).

## How to build

You need cmake and a C++ compiler (we used g++/MinGW on Windows, should work on Linux/Mac too).

```
<<<In-Source Build Dir>>>
mkdir build
cd build
cmake ..
cmake --build .
.\Debug\Project2.exe

OR

<<<From Project Root>>>
cmake -S . -B build
cmake --build build
.\build\Debug\Project2.exe
```

This should give you an executable called `Project2` (or `Project2.exe` on Windows).

Make sure `lap_times.csv` is in the same folder as the executable when you run it, otherwise option 1 won't work.

## How to use it

Just run the program and a menu pops up:

```
1. Load F1 Dataset (lap_times.csv)
2. Run Benchmarks (Linear vs Quadratic)
3. Search for a Specific Lap (+ Anomaly Check)
4. Show Results Table
5. Scan Driver for Flagged Laps
6. Run Tests
7. Exit
```

**Start with option 1** - you have to load the data first or nothing else will work.

After that:

- **Option 2** runs the benchmark at different load factors (0.5 - 0.9) and shows collision counts + timing for both hash table types
- **Option 3** lets you look up a specific lap. Give it a Race ID, Driver ID, and Lap Number seperated by spaces. It'll show the lap time and tell you if its a normal/slow/fast lap compared to that driver's average
- **Option 4** shows a formatted table of all the benchmark results from option 2
- **Option 5** scans all laps for a given driver and lists any that were flagged as anomalies
- **Option 6** runs some basic unit tests
- **Option 7** exits

## Example lookup (option 3)

```
Enter Race ID, Driver ID, and Lap Number: 841 1 3
```

You can find valid IDs by looking at the CSV file directly.

## Notes

- A log file called `run_log.txt` gets created when you run the program, it just tracks what you did during the session
- Anomaly thresholds are hardcoded in `anomaly.h` if you want to change what counts as a "slow" or "fast" lap
