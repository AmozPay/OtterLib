FROM fedora:37 as builder
WORKDIR /app
RUN dnf update -y
RUN dnf install -y \
    gcc g++ \
    pip \
    cmake
RUN pip install conan
RUN conan profile new --detect default

COPY OtterLib OtterLib
WORKDIR /app/OtterLib
RUN cmake -S . -B build
RUN echo debug
RUN cmake --build build --target OtterLib


WORKDIR /app
COPY games games
COPY CMakeLists.txt .
RUN ls games

RUN cmake -S . -B build

RUN cmake --build build --target r-type_server
CMD ["/app/build/games/rtype/bin/r-type_server"]
