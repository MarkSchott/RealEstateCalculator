#!/bin/bash
cd definitions
pr -m -t initial_definitions.txt ../input.txt
pr -m -t definitions.txt ../Calculated_Values.txt
