# SD-E1 Starter

This project contains a deliberately incorrect parallel implementation.

## Build (serial)

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Release
cmake --build build
./build/event_processor
```

## Enable OpenMP

```bash
cmake -B build-omp -G Ninja -DCMAKE_BUILD_TYPE=Release -DENABLE_OPENMP=ON
cmake --build build-omp
./build-omp/event_processor
```

## What to fix

- Correctness: race conditions on shared accumulators
- Performance: false sharing on per-thread counters

