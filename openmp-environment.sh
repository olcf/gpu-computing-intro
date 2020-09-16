#!/bin/bash

module reset
module load xl
module load cuda

export PS1="[\u@\h: \w]$ "
alias ls="ls --color"
