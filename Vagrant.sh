#!/usr/bin/env bash

# packages

which apt-get && {
  sudo apt-get -y install curl vim ack-grep
  sudo apt-get -y install valgrind kcachegrind
}

# roundup

cd /tmp
curl -L http://github.com/bmizerany/roundup/tarball/v0.0.5 | tar xvzf -
cd bmizerany-roundup* && ./configure && make && sudo make install

# papi

cd /tmp
curl -L http://icl.cs.utk.edu/projects/papi/downloads/papi-4.1.3.tar.gz | tar xvzf -
cd papi-4.1.3 && make && sudo make install

