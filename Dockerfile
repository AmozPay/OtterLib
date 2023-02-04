FROM fedora:37 as builder
WORKDIR /app
RUN dnf update -y
RUN dnf install -y \
    gcc g++ \
    pip \
    cmake
RUN pip install conan
COPY OtterLib OtterLib
COPY games games
COPY CMakeLists.txt .
RUN ls games
RUN mkdir OtterLib/build

WORKDIR /app/OtterLib/build

WORKDIR /app
RUN conan profile new --detect default
RUN cmake -S . -B build

RUN cmake --build build --target r-type
CMD ["/app/build/games/rtype/bin/r-type_server"]
