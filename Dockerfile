FROM python:3.12-slim

WORKDIR /app

RUN apt-get update && apt-get install -y g++ libgtest-dev cmake && rm -rf /var/lib/apt/lists/*

RUN cd /usr/src/googletest && cmake . && cmake --build . --target install

COPY pyproject.toml .
RUN pip install --no-cache-dir pytest

COPY . .

RUN g++ -std=c++17 -Isrc -o runTests tests/test_proc_story_001.cpp src/FieldProcessor.cpp -lgtest -lgtest_main -pthread

CMD ["./runTests"]
