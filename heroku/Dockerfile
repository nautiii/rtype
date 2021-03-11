FROM debian:stretch-slim
RUN apt-get update
RUN apt-get install -y --no-install-recommends \
    ca-cacert \
    cmake \
    build-essential \
    libboost-all-dev \
    libssl-dev \
    wget \
    zlib1g-dev

# install the repo
WORKDIR /app
COPY . /app
RUN wget https://github.com/EpitechIT2020/B-CPP-501-PAR-5-1-rtype-gaetan.depin/heroku/r-type.tar.gz
RUN ./project_decompression.sh
RUN mkdir build
RUN conan install . --build=missing

# Start
WORKDIR /app/build 
RUN cmake . 
RUN cmake --build .
CMD ["./r-type", "--port", "8000"]