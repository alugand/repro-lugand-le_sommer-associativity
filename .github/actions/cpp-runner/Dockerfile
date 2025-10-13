FROM debian:latest

RUN apt-get update && apt-get install -y g++

COPY entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

ENTRYPOINT ["/entrypoint.sh"]