FROM debian:latest

WORKDIR /app

COPY . /app/

RUN apt-get update && apt-get install -y g++ build-essential

RUN g++ -o banking banking.cpp

CMD ["./banking"]
