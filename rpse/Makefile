#!/bin/bash
CC = gcc
CFLAGS = -Wall -g -Wextra -Iheader_files

all: executable_files/rpse

object_files/rpsecore-util.o: source_files/rpsecore-util.c header_files/rpsecore-util.h
	$(CC) $(CFLAGS) -c $< -o $@

object_files/rpsecore-g1.o: source_files/rpsecore-g1.c header_files/rpsecore-g1.h
	$(CC) $(CFLAGS) -c $< -o $@

object_files/rpsecore-g2.o: source_files/rpsecore-g2.c header_files/rpsecore-g2.h
	$(CC) $(CFLAGS) -c $< -o $@

object_files/main.o: source_files/main.c header_files/rpsecore-util.h header_files/rpsecore-g1.h header_files/rpsecore-g2.h
	$(CC) $(CFLAGS) -c $< -o $@

executable_files/rpse: object_files/main.o object_files/rpsecore-util.o object_files/rpsecore-g1.o object_files/rpsecore-g2.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f object_files/*.o executable_files/rpse