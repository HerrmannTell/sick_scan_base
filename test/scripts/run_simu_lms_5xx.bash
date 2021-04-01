#!/bin/bash

# 
# Run sick_generic_caller with sick_lms_5xx.launch
# 

pushd ../..


pushd ./demo
rm -f ./scan.jpg ./scan.csv
firefox ./image_viewer.html &
sleep 1
popd

python3 ./test/emulator/test_server.py --scandata_file=./test/emulator/scandata/20210302_lms511.pcapng.scandata.txt --scandata_frequency=20.0 --tcp_port=2112 &
sleep 1
./build_x64/sick_generic_caller ./launch/sick_lms_5xx.launch hostname:=127.0.0.1 &

sleep 60

pkill -f ./test/emulator/test_server.py
killall sick_generic_caller
popd

