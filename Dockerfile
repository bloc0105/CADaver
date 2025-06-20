FROM debian:latest


# You need build essential in order to have compatibility between the gcc compiler and CMake

#AI's opinion on build-essential
# The build-essential package in Debian and Ubuntu is a meta-package
# that includes essential tools for building software from source code.
# It's not a single program, but rather a collection of other packages,
# including compilers, libraries, and build tools. Essentially, it
# provides the basic environment needed to compile and build software
# on a Linux system. 
RUN apt update && apt install git cmake curl build-essential python3
RUN git clone https://github.com/microsoft/vcpkg.git
RUN cd vcpkg && ./bootstrap-vcpkg.sh
ENV VCPKG_ROOT=vcpkg
ENV PATH=$VCPKG_ROOT:$PATH

RUN git clone https://github.com/bloc0105/CADaver.git

