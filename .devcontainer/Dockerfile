# .devcontainer/Dockerfile
FROM rootproject/root:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        ca-certificates \
        curl \
        git \
        cmake \
        ninja-build \
        g++ \
        gdb \
        valgrind \
        python3 \
        python3-pip && \
    \
    # Clang + sanitizer runtimes (NO compiler-rt package on Ubuntu questing).
    (apt-get install -y --no-install-recommends \
        clang-20 \
        clang-tidy-20 \
        llvm-20 \
        lld-20 \
        libclang-rt-20-dev \
     || apt-get install -y --no-install-recommends \
        clang \
        clang-tidy \
        llvm \
        lld \
        libclang-rt-dev) && \
    \
    # Ensure clang/clang++ exist even if only versioned binaries were installed
    if command -v clang-20 >/dev/null 2>&1; then \
        ln -sf "$(command -v clang-20)"   /usr/local/bin/clang; \
        ln -sf "$(command -v clang++-20)" /usr/local/bin/clang++; \
        if command -v clang-tidy-20 >/dev/null 2>&1; then \
          ln -sf "$(command -v clang-tidy-20)" /usr/local/bin/clang-tidy; \
        fi; \
    fi && \
    \
    # perf (optional, do not fail build)
    (apt-get install -y --no-install-recommends linux-tools-common linux-tools-generic || true) && \
    (apt-get install -y --no-install-recommends linux-perf || true) && \
    \
    rm -rf /var/lib/apt/lists/*

RUN python3 -m pip install --break-system-packages \
        pytest \
        pytest-cov \
        mkdocs \
        mkdocs-material

WORKDIR /work
