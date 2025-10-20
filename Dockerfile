FROM debian:latest

WORKDIR /app

COPY . /app/

RUN apt-get update && apt-get install -y g++ build-essential

RUN g++ -O2 -ffloat-store -fno-fast-math -o number number.cpp

CMD ["./number"]
