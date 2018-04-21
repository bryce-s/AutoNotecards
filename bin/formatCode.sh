#!/bin/bash
set -x
# npm -g install js-beautify (for js and html..)
# recurse through dir applying formatters
for f in autonotecards/*;
  do 
     [ -d $f ] && cd "$f" && autopep8 --in-place --aggressive --aggressive *.py && js-beautify -r *.html
     cd ..
  done; 