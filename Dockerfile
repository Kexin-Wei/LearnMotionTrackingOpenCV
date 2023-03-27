# Use the official Ubuntu image as the base
FROM ubuntu:20.04

# Set environment variables to avoid interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Update the package index and install required packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    unzip \
    yasm \
    pkg-config \
    libavcodec-dev \
    libavformat-dev \
    libswscale-dev \
    python3-dev \
    python3-numpy \
    python3-pip \
    libtbb2 \
    libtbb-dev \
    libjpeg-dev \
    libpng-dev \
    libtiff-dev \
    libavformat-dev \
    libpq-dev

# Download and build OpenCV
RUN cd ~ && \
    git clone https://github.com/opencv/opencv.git && \
    git clone https://github.com/opencv/opencv_contrib.git && \
    cd opencv && \
    mkdir build && \
    cd build && \
    cmake -D CMAKE_BUILD_TYPE=Release \
          -D CMAKE_INSTALL_PREFIX=/usr/local \
          -D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
          -D PYTHON3_PACKAGES_PATH=/usr/lib/python3.8/dist-packages \
          -D BUILD_opencv_python2=OFF \
          -D BUILD_EXAMPLES=OFF \
          -D WITH_TBB=ON \
          -D WITH_QT=OFF \
          .. && \
    make -j$(nproc) && \
    make install && \
    ldconfig

# Set the default command to run a Bash shell
CMD ["bash"]
