FROM fedora:37 as builder
WORKDIR /app
RUN dnf update -y
RUN dnf install -y \
    gcc g++ \
    pip \
    cmake
RUN pip install conan==1.57.0
RUN conan profile new --detect default

COPY OtterLib OtterLib
COPY games games
COPY CMakeLists.txt .
RUN cmake -DBUILD_RELEASE=ON -DBUILD_TESTING=OFF -S . -B build

RUN cmake --build build --target r-type_server --config Release
CMD ["/app/build/games/rtype/bin/r-type_server"]
