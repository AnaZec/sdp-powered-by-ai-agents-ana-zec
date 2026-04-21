FROM python:3.12-slim

WORKDIR /app

RUN apt-get update && apt-get install -y g++ libgtest-dev cmake && rm -rf /var/lib/apt/lists/*

RUN cd /usr/src/googletest && cmake . && cmake --build . --target install

COPY pyproject.toml .
RUN pip install --no-cache-dir pytest

COPY . .

RUN g++ -std=c++17 -Isrc -o minesweeper src/main.cpp src/InputParser.cpp src/FieldProcessor.cpp src/OutputFormatter.cpp
RUN g++ -std=c++17 -Isrc -o runTests tests/*.cpp src/InputParser.cpp src/FieldProcessor.cpp src/OutputFormatter.cpp -L/usr/local/lib -lgtest_main -lgtest -pthread

CMD ["./runTests"]
