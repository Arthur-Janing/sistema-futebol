CC = gcc
TARGET = sistema
SOURCE = ./src
INCLUDE = ./include
OBJETOS = ./objs


all: obj
	
	$(CC) $(OBJETOS)/utils.o $(OBJETOS)/menus.o $(OBJETOS)/arquivos.o $(OBJETOS)/cadastros.o $(OBJETOS)/relatorios.o $(OBJETOS)/consultas.o $(OBJETOS)/main.o -o $(TARGET)
	


obj:
	
	@mkdir -p $(OBJETOS)
	
	$(CC) -c $(SOURCE)/utils.c -I$(INCLUDE) -o $(OBJETOS)/utils.o
	$(CC) -c $(SOURCE)/menus.c -I$(INCLUDE) -o $(OBJETOS)/menus.o
	$(CC) -c $(SOURCE)/arquivos.c -I$(INCLUDE) -o $(OBJETOS)/arquivos.o
	$(CC) -c $(SOURCE)/cadastros.c -I$(INCLUDE) -o $(OBJETOS)/cadastros.o
	$(CC) -c $(SOURCE)/relatorios.c -I$(INCLUDE) -o $(OBJETOS)/relatorios.o
	$(CC) -c $(SOURCE)/consultas.c -I$(INCLUDE) -o $(OBJETOS)/consultas.o
	$(CC) -c main.c -I$(INCLUDE) -o $(OBJETOS)/main.o

clear:
	rm -f $(TARGET)
	rm -f $(OBJETOS)/*.o
	