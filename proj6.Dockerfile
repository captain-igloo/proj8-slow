FROM ubuntu:focal

COPY test-proj.cpp /proj-slow/

RUN apt update \
    && apt install -y --no-install-recommends \
    g++ \
    libproj-dev \
    && cd /proj-slow \
    && g++ test-proj.cpp -lproj
