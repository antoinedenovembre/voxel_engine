#!/bin/bash

BOLD='\033[1m'
UNDERLINE='\033[4m'
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

log()
{
    echo "[$(date +'%Y-%m-%d %H:%M:%S')] $1"
}

log_error()
{
    echo -e "${RED}[$(date +'%Y-%m-%d %H:%M:%S')] ERROR: $1${NC}"
}

log_success()
{
    echo -e "${GREEN}[$(date +'%Y-%m-%d %H:%M:%S')] SUCCESS: $1${NC}"
}

log_info()
{
    echo -e "${BOLD}[$(date +'%Y-%m-%d %H:%M:%S')] INFO: $1${NC}"
}

FORCE_BUILD=false
parse_args()
{
    while [[ "$1" == -* ]]; do
        case "$1" in
            -h|--help)
                echo "Usage: $0 [options]"
                echo "Options:"
                echo "  -h, --help    Show this help message and exit"
                echo "  -f, --force   Force rebuild by removing existing build directory"
                exit 0
                ;;
            -f|--force)
                FORCE_BUILD=true
                shift
                ;;
            *)
                log_error "Unknown option: $1"
                exit 1
                ;;
        esac
    done
}

main()
{
    parse_args "$@"

    log_info "Starting build process..."
    if [ "$FORCE_BUILD" = true ]; then
        log_info "Forcing build by removing existing build directory..."
        rm -rf build
    fi

    log_info "Creating build directory..."
    mkdir -p build

    log_info "Running CMake to configure the project..."
    cmake -S . -B build

    log_info "Building the project using CMake..."
    cmake --build build -j

    if [ $? -eq 0 ]; then
        log_success "Build completed successfully!"
    else
        log_error "Build failed. Please check the output for details."
        exit 1
    fi
}

main "$@"
