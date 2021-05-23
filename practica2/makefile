#FICHERO : makefile
#FECHA: 19/03/2016
#AUTOR: Alejandro Jerónimo Fuentes
#UTILIDAD: Automatizar el proceso de compilación del proyecto led
#USO: make o make <regla>


##################DECLARACIÓN DE VARIABLES###############################

#Variable que muestra el compilador que se va a utilizar durante el proceso
CC=g++

#Variable que muestra el directorio donde se encuentran los archivos de cabecera
INCLUDE_DIR=./include

#Variable que muestra el archivo ejecutable
EXEC= bin/main

#Variable que muestra los archivos objeto
OBJS= obj/bloqueLed.o obj/main.o

#Variable que muestra las cabeceras
HDRS= include/bloqueLed.h

##########################################################################



######################IMPLEMENTACIÓN DE REGLAS############################


#Genera el ejecutable test directamente al ejecutar make
all: $(EXEC)


#Genera el archivo objeto bloqueLed.o
obj/bloqueLed.o: src/bloqueLed.cpp $(HDRS)
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo objeto main.o
obj/main.o: src/main.cpp obj/bloqueLed.o
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo ejecutable
$(EXEC): $(OBJS)
	$(CC) -g $(OBJS) -o $@


#Elimina todos los archivos objeto del proyecto
clean:							
	echo "Limpiando..."
	rm obj/*.o


#Elimina los archivos objeto y el ejecutable
mrproper: clean					
	rm $(EXEC)

############################################################################