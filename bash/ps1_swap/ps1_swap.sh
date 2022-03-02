#! /usr/bin/env bash

export OLD_PS1="\[\033[01;32m\]\u \033[01;34m\]@ \W\[\033[00m\] \$ "
#${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\W\[\033[00m\]\$ '
                               
function ps1_swap() {
    temp=$PS1
    export PS1=$OLD_PS1
    export OLD_PS1=$temp
}

