FROM fedora:37 as builder
WORKDIR /app
RUN dnf update -y
RUN dnf install -y \
    cmake \
    pip \
    gcc
RUN dnf install -y g++
RUN pip install conan
COPY OtterLib OtterLib
COPY games games
COPY CMakeLists.txt .
RUN ls games
RUN mkdir OtterLib/build

WORKDIR /app/OtterLib/build
RUN conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=true

WORKDIR /app
RUN cmake -S . -B build
RUN cmake --build build
RUN ls ~/.conan
RUN ls build/games/rtype
CMD ["/app/build/games/rtype/bin/r-type_server"]
