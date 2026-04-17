FROM python:3.12-slim

WORKDIR /app

RUN apt-get update && apt-get install -y g++ && rm -rf /var/lib/apt/lists/*

COPY pyproject.toml .
RUN pip install --no-cache-dir pytest

COPY . .

CMD ["python", "-m", "pytest", "tests/", "-v", "--tb=short"]
