#! /usr/bin/env bash

set -o xtrace
pytest -p no:cacheprovider -k test_fill_db -s
pytest -p no:cacheprovider -m smoketest -s
exit
