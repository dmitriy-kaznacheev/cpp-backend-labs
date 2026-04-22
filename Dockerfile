FROM ubuntu:22.04
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /app
COPY . .
RUN cmake -S . -B build && \
    cmake --build build
CMD ["ctest", "--test-dir", "build", "--verbose"]
