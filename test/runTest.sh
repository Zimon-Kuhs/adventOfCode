#! /bin/sh

startDir="$(readlink -f "$(pwd)")"
this="$(readlink -f "$0")"

###################################################### Functions ######################################################

say () {
    printf "[%s]: %s\n" "$this" "$1"
}

fail () {
    stop "$1"
    exit 1
}

finish () {
    stop "$1"
    exit 0
}

stop () {
    say "$1"
    say "Exiting."
    cd "$startDir" || :
}

usage() {
    cat <<EOF
usage: $0 year

OPTIONS:                                                    DEFAULT VALUE
    <NO OPTIONS>                                            <NO>
EOF
}

#######################################################################################################################

if [ -z "$1" ]; then
    usage
    exit
fi

cd "$(dirname "$this")" || :

if [ "$1" = "2015" ]; then
    fail "Year $1 not implemented."
elif [ "$1" = "2016" ]; then
    fail "Year $1 not implemented."
elif [ "$1" = "2017" ]; then
    fail "Year $1 not implemented."
elif [ "$1" = "2018" ]; then
    fail "Year $1 not implemented."
elif [ "$1" = "2019" ]; then
    fail "Year $1 not implemented."
elif [ "$1" = "2020" ]; then
    fail "Year $1 not implemented."
elif [ "$1" = "2021" ]; then
    cd .. && python3 test/test2021.py
elif [ "$1" = "2022" ]; then
    shift 1
    cd "../src/year2022" && make && ./adventOfCode "$@"
    sudo rm -f ./adventOfCode
elif [ "$1" = "2023" ]; then
    fail "Year $1 not implemented."
else
    fail "Year $1 not implemented and is currently not considered to be either."
fi

cd "$startDir" || :
