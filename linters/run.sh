#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
if [ "${1}" == "--local" ]; then
 CPPCHECK="cppcheck"
else
 CPPCHECK="./linters/cppcheck/cppcheck"
fi
${CPPCHECK} project tests --enable=all --force --error-exitcode=1 -I project/include --suppress=missingIncludeSystem # --check-config

print_header "RUN cpplint.py"
python2.7 ./linters/cpplint/cpplint.py --extensions=c --extensions=h project/include/* project/src/*
print_header "RUN cpplint.py c++"
python2.7 ./linters/cpplint/cpplint.py --extensions=cpp --filter=-runtime/references,-legal/copyright,-build/include_subdir,-whitespace/line_length tests/*



print_header "SUCCESS"