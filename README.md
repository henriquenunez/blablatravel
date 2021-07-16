# blablatravel
Database assignment for SCC0240

## Installation

### Requirements

Note: the `setup.sh` script only works on Arch linux currently.

Run: `./setup.sh`. It will install the PostgreSQL libraries. You can install
them yourself too.

### Build

Run: `./build.sh` to build.

## Running

To run, you need to pass the connection string as an environment variable, such
as:

`PSQL_CONN="user = postgres password = <your_password> hostaddr = <your_host> port = <your_port>" ./run.sh`

