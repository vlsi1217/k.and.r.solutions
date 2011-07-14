#!/usr/bin/env bash

# packages

which apt-get && sudo apt-get -y install curl vim valgrind

# roundup

cd /tmp
curl -L http://github.com/bmizerany/roundup/tarball/v0.0.5 | tar xvzf -
cd bmizerany-roundup* && ./configure && make && sudo make install

