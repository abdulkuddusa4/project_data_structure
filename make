#!/usr/bin/bash
gcc main.c -o main -lm `pkg-config --cflags --libs gtk+-3.0`