EXEC = main

# Fichiers sources
SRCS = main.c utils.c algo_tri.c

# Fichiers objets
OBJS = $(SRCS:.c=.o)

# Compilateur et options
CC = gcc

# Règle par défaut
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Compilation des fichiers objets
%.o: %.c
	$(CC) -c $< -o $@

