# OpenCalc

OpenCalc is a command-line calculator that performs basic arithmetic operations and also supports paranthesized expressions.

## Install Package

### Prerequisites

Ensure you have the following installed on your system:

- Fedora (or any compatible RPM-based distribution)
- `rpm` command-line tools

### Steps to Install

1. Download the RPM package from GitHub releases

```bash
curl -L -H 'User-Agent: Mozilla/5.0' -o OpenCalc-1.0-1.fc39.x86_64.rpm https://github.com/swarraaa/OpenCalc/releases/download/v1.0/OpenCalc-1.0-1.fc39.x86_64.rpm
```

2. Install the RPM package

```bash
sudo dnf install ~/Downloads/OpenCalc-1.0-1.fc39.x86_64.rpm
```

## Uninstall Package

```bash
sudo dnf remove OpenCalc
```

## Usage

To use OpenCalc, simply run the command:

```bash
OpenCalc
```

You can enter your calculations directly in the terminal.

## Contributing

Contributing is the heart of open source. It is always appreciated. If you would like to contribute to OpenCalc, please fork the repository and submit a pull request.
