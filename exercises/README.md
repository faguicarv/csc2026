# Exercises

This directory contains all hands-on exercises for the course.

Each exercise is self-contained and designed to be completed in a short, focused session.
Students must work in their own GitHub fork and submit solutions via pull requests.

## Workflow (mandatory)

1. Fork the repository on GitHub.
2. Clone your fork in LXPLUS or open a GitHub CodeSpace
3. Create one branch per exercise.
4. Commit your changes.
5. Open a pull request from your fork to the upstream repository.

Do not work directly on `main`.

---

## Exercise list

### TT-E1 — Debugging and Sanitizers
**Folder:** `TT-E1-debugging-sanitizers`

**Goal**
- Learn to use AddressSanitizer and UndefinedBehaviorSanitizer.
- Identify and fix real memory bugs.

**Skills**
- Reading sanitizer reports
- Debugging C++ memory errors

---

### TT-E2 — Documentation and CI
**Folder:** `TT-E2-docs-and-ci`

**Goal**
- Write minimal technical documentation.
- Understand how documentation fits into CI.

**Skills**
- MkDocs
- CI feedback loops

---

### SD-E1 — Parallel Event Processing
**Folder:** `SD-E1-parallel-event-processing`

**Goal**
- Make parallel code correct before making it fast.
- Understand nondeterminism and race conditions.

**Skills**
- OpenMP
- Thread safety
- Deterministic testing

---

### SD-E2 — Benchmark and Optimize
**Folder:** `SD-E2-benchmark-and-optimize`

**Goal**
- Measure performance correctly.
- Apply simple, justified optimizations.

**Skills**
- Microbenchmarking
- Data layout
- Performance reasoning

---

## How to work on an exercise

Each exercise contains a `starter` directory.

1. Enter the exercise starter directory.
2. Read the local `README.md`.
3. Configure and build using CMake.
4. Run tests and binaries.
5. Modify code until requirements are met.

If tests pass and CI is green, the exercise is complete.

---

## Submission

- One branch per exercise.
- One pull request per exercise.
- PR description must explain:
  - What was wrong.
  - What was changed.
  - How correctness was verified.
