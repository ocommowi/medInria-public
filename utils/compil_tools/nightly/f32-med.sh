#!/usr/bin/env sh
#no need for doc. f64 does it
./installer.py  -f run_linux.cfg -f run_fed.cfg -f run_f32-med.cfg -f run_nightly_linux.cfg -f compiler.cfg 

./installer.py -f run_linux.cfg -f run_fed.cfg -f run_f32-med.cfg -f run_nightly_linux.cfg -f compiler.cfg -f debug.cfg --no-update-dirs --no-package --no-package-deps &> /dev/null
