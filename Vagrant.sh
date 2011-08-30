#!/usr/bin/env bash

set -e

# prepare

(
  rm -rf ~/.config
  mkdir -p ~/.config

  sudo chown -R vagrant /usr/local/lib
  sudo chown -R vagrant /usr/local/src
)

# packages

(
  sudo apt-get -y update
  sudo apt-get -y upgrade
  sudo apt-get -y install curl vim tree screen "ack-grep"
  sudo apt-get -y install valgrind kcachegrind oprofile
)

# ruby for command-t

(
  which ruby || {
    sudo apt-get -y install ruby1.9.1-full
    sudo ln $(which ruby1.9.1) /bin/ruby
  }
)

# roundup

(
  cd /usr/local/src

  ls bmizerany-roundup* || {
    curl -L http://github.com/bmizerany/roundup/tarball/v0.0.5 | tar xvzf -
    (
      cd bmizerany-roundup* || exit 1

      # bashize
      sed -i'' 's/#!\/bin\/sh/#!\/bin\/bash/g' roundup.sh

      ./configure && make && sudo make install
    )
  }
)

# papi

(
  cd /usr/local/src

  ls papi-4.1.3 || true || {
    curl -L http://icl.cs.utk.edu/projects/papi/downloads/papi-4.1.3.tar.gz | tar xvzf -
    (cd papi-4.1.3/src && sudo ./configure && sudo make && sudo make install)
  }
)

# vim

(
  cd /usr/local/src

  [[ -d vim ]] || {
    mkdir vim
    cd vim
    curl "ftp://ftp.vim.org/pub/vim/unix/vim-7.3.tar.bz2" | tar jxf - --strip 1
    ./configure --enable-rubyinterp # for command-t
    make && sudo make install
  }
)

# ingest

(
  for file in $(find ~/.config -type f); do
    echo source $file >> ~/.config/.ingest
  done

  grep ".ingest" ~/.bash_profile || {
    echo source ~/.config/.ingest >> ~/.bash_profile
    source ~/.bash_profile
  }
)

exit 0

