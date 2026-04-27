FROM ubuntu:22.04
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    python3 \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install "conan>=2.0"
RUN conan profile detect --name default

WORKDIR /app
COPY . .

RUN conan install . --build=missing && \
    cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=./build/Release/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release && \
    cmake --build build
CMD ["ctest", "--test-dir", "build", "--verbose"]
