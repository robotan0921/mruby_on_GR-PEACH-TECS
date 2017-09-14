#!/bin/sh
./tecsmerge.rb -e ./gen $1
cd $1
rm *.c_*
rm *.h_*
