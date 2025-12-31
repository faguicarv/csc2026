# TT-E1 Debugging with Sanitizers

This exercise is a deliberately broken "track reconstruction" micro-library.

Students should **not** start by reading code. The expected workflow is:

1. Run once without sanitizers to see the lack of useful diagnostics.
2. Enable sanitizers (ASan + UBSan) and re-run.
3. Fix the first reported bug, then repeat.

## What is broken

The starter contains three bugs in `TrackReconstructor`:

- Heap buffer overflow (off-by-one loop bound)
- Memory leak (`new[]` without `delete[]`)
- Use-after-free (returns pointer to freed heap memory)

## How to run

From the exercise starter directory:

```bash
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/analyze
```

Enable sanitizers:

```bash
cmake -B build-asan -G Ninja -DCMAKE_BUILD_TYPE=Debug -DENABLE_SANITIZERS=ON
cmake --build build-asan
./build-asan/analyze
```
