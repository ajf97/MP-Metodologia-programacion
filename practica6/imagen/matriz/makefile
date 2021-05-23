#FICHERO : makefile
#FECHA: 26/05/2016
#AUTORES: Alejandro Jerónimo Fuentes y Elvira Castillo
#UTILIDAD: Automatizar el proceso de compilación de los ejecutables
#USO: make o make <regla>


##################DECLARACIÓN DE VARIABLES###############################

#Variable que muestra el compilador que se va a utilizar durante el proceso
CC=g++

#Variable que muestra el directorio donde se encuentran los archivos de cabecera
INCLUDE_DIR=./include


#Variable que muestra los archivos objeto
OBJS= obj/imagen.o obj/pgm.o obj/testimagen.o

#Variable que muestra las bibliotecas
LIB= lib/libimagen.a

#Variable que muestra las cabeceras
HDRS= include/imagen.h include/pgm.h

##########################################################################



######################IMPLEMENTACIÓN DE REGLAS############################


#Genera el ejecutable test directamente al ejecutar make
all: bin/testimagen bin/testplano bin/arteASCII2 bin/suma


#Documentación
documentacion:
	doxygen doc/doxys/Doxyfile


#Genera el archivo objeto pgm.o
obj/pgm.o: src/pgm.cpp include/pgm.h
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo objeto imagen.o
obj/imagen.o: src/imagen.cpp $(HDRS)
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo objeto lista.o
obj/lista.o: src/lista.cpp include/lista.h
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Creación de la biblioteca con los archivos pgm.o imagen.o
$(LIB): obj/imagen.o obj/pgm.o obj/byte.o obj/lista.o
	ar rvs $@ $^


#Genera el archivo objeto testimagen.o
obj/testimagen.o: src/testimagen.cpp include/imagen.h
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo objeto testplano.o
obj/testplano.o: src/testplano.cpp include/imagen.h
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo objeto byte.o
obj/byte.o: src/byte.cpp include/byte.h
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo objeto testarteASCII.o
#obj/testarteASCII.o: src/testarteASCII.cpp include/imagen.h
#	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo objeto arteASCII2.o
obj/arteASCII2.o: src/arteASCII2.cpp include/imagen.h include/lista.h
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)


#Genera el archivo ejecutable testimagen
bin/testimagen: $(LIB) obj/testimagen.o
	$(CC) -g obj/testimagen.o -limagen -o $@ -Llib


#Genera el archivo ejecutable testplano
bin/testplano: $(LIB) obj/testplano.o
	$(CC) -g obj/testplano.o -limagen -o $@ -Llib


#Genera el archivo ejecutable arteASCII2.o
bin/arteASCII2: $(LIB) obj/arteASCII2.o
	$(CC) -g obj/arteASCII2.o -limagen -o $@ -Llib

#Genera el archivo objeto suma.o
obj/suma.o: src/suma.cpp include/imagen.h
	$(CC) -g -c $< -o $@ -I$(INCLUDE_DIR)

#Genera el archivo ejecutable suma.o
bin/suma: $(LIB) obj/suma.o
	$(CC) -g obj/suma.o -limagen -o $@ -Llib

#Elimina todos los archivos objeto del proyecto
clean:
	echo "Limpiando..."
	rm obj/*.o
	rm lib/*


#Elimina los archivos objeto y los ejecutables
mrproper: clean
	rm bin/*

############################################################################
