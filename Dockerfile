FROM debian:latest

WORKDIR /app

COPY . /app/

RUN apt-get update && apt-get install -y g++ build-essential

RUN mkdir /app/results

RUN g++ -o number number.cpp

CMD ["./number"]
