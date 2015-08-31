#
#   Docker image for building libprocess and bundled mesos software
#
# This requires at least volume #1 to be mounted. #2 is only required if you
# want the results outside of this docker image:
#   1. meso git repo mounted at /var/workspace/source (BUILD_SOURCE)
#   2. target directory at /var/workspace/target (BUILD TARGET)

FROM ubuntu:trusty

env BUILD_SOURCE /var/workspace/source
env BUILD_TARGET /var/workspace/target

RUN apt-key adv --fetch-keys http://repo.rcsops.com/key/rcs-repo-pubkey.asc
RUN echo "deb http://repo.rcsops.com/debian/prod/ trusty main" > /etc/apt/sources.list.d/rcsops.list
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -y \
    automake \
    curl \
    build-essential \
    libapr1-dev \
    libcurl4-nss-dev \
    libsvn1-dev \
    libtool \
    python \
    python-dev \
    python-setuptools \
    vim

# Build and install libprocess and stout
WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess
RUN ./bootstrap
RUN mkdir -p build
WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess/build
RUN ../configure --prefix=${BUILD_TARGET}
RUN make && make install

# Install boost headers
RUN cp -av ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/boost-*/boost ${BUILD_TARGET}/include/

# Build and install glog
WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/glog-0.3.3/
RUN make distclean
WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/glog-0.3.3/build/
RUN ../configure --prefix=${BUILD_TARGET}
RUN make && make install

# Build and install gmock
#WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/gmock-1.7.0/build
#RUN ../configure --prefix=${BUILD_TARGET}
#RUN make && make install

# Build and install libev
WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/libev-4.15/build
RUN ../configure --prefix=${BUILD_TARGET}
RUN make && make install

# Install picojson headers
RUN cp -av ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/picojson-4f93734/picojson.h ${BUILD_TARGET}/include/

# Build and install protobuf
WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/protobuf-2.5.0/
RUN make distclean
WORKDIR ${BUILD_SOURCE}/3rdparty/libprocess/build/3rdparty/protobuf-2.5.0/build
RUN ../configure --prefix=${BUILD_TARGET}
RUN make && make install

ENTRYPOINT /bin/bash
