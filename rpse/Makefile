set CC = gcc
CFLAGS = -Wall -Wextra -Iheader_files

all: rpse

source_files/move_definition.o: source_files/move_definition.c header_files/move_definition.h
	$(CC) $(CFLAGS) -c $< -o $@

source_files/gamemode_selection.o: source_files/gamemode_selection.c header_files/gamemode_selection.h
	$(CC) $(CFLAGS) -c $< -o $@

source_files/gamemode_1.o: source_files/gamemode_1.c header_files/gamemode_1.h
	$(CC) $(CFLAGS) -c $< -o $@

source_files/gamemode_2.o: source_files/gamemode_2.c header_files/gamemode_2.h
	$(CC) $(CFLAGS) -c $< -o $@

source_files/main.o: source_files/main.c header_files/move_definition.h header_files/gamemode_selection.h header_files/gamemode_1.h header_files/gamemode_2.h
	$(CC) $(CFLAGS) -c $< -o $@

rpse: source_files/move_definition.o source_files/gamemode_selection.o source_files/gamemode_1.o source_files/gamemode_2.o source_files/main.o
	$(CC) $^ -o $@

clean:
	rm -f source_files/*.o myprogram
