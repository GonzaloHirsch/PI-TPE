Trabajo practico final para Programación Imperativa (Primer Cuatrimestre 2018)
Fecha: 12/07/2018

------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------

Contenidos de este documento:
	1 - Integrantes del grupo.
	2 - Contenidos de la carpeta que se entregó.
	3 - Como compilar.
	4 - Como ejecutar.
	5 - Algunas consideraciones.
		5.1 - Consideraciones respecto de los queries.
		5.2 - Consideraciones respecto de los archivos.
	6 - Información extra.
	
------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------

1 - Integrantes del grupo:
	- Gonzalo Hirsch - 59089
	- Francisco Letterio - 58408
	- Ignacio Villanueva - 59000

------------------------------------------------------------------------------------------------------------------------------------------

2 - Contenidos de la carpeta que se entregó:
	Se entregó la carpeta "PI_TPE":
	- README.txt
	- main.c
	- ErrorHandler.c
	- ErrorHandler.h
	- ProcessData.c
	- ProcessData.h
	- Querys.c
	- Querys.h
	- Types.h
	- Datasets (carpeta con los .csv):
		- archivoAeropuertos.csv
		- archivoVuelos.csv
	- ADT (carpeta con los archivos de los ADT):
		- AirportADT.c
		- AirportADT.h
		- ListADT.c
		- ListADT.h
		- MovementADT.c
		- MovementADT.h
		
------------------------------------------------------------------------------------------------------------------------------------------

3 - Como compilar:
	- Primero moverse dentro del sistema hasta tener como Current Working Directory(CWD) 
	la carpeta donde se encuentran los archivos ("PI_TPE").
	- Segundo, escribir el comando(el signo "$" indica la terminal):
		$	gcc *.c ./ADT/*.c -o OUTPUT_NAME -Wall -pedantic -std=c99 -fsanitize=address
	- Tener en cuenta que OUTPUT_NAME es el nombre con que va a salir el ejecutable del programa, 
	cámbielo a gusto(Cumpliendo las normas para nombrar archivos).

------------------------------------------------------------------------------------------------------------------------------------------

4 - Como ejecutar:
	- Primero moverse dentro del sistema hasta tener como Current Working Directory(CWD) la carpeta donde se encuentran los archivos.
	- Segundo, escribir el comando(el signo "$" indica la terminal):
		$	./OUTPUT_NAME AÑO_A_ELECCION
	- Tener en cuenta que OUTPUT_NAME es el mismo nombre con que se compiló, y el AÑO_A_ELECCION es un año entre 2014 y 2018.

------------------------------------------------------------------------------------------------------------------------------------------

5 - Algunas consideraciones:
	5.1 - Algunas consideraciones respecto de los queries:
		- Para el Query 2, los vuelos que en la clasificación del vuelo estaban marcados como "N/A", 
		al no saber si son internacionales o no, fueron contados como internacionales.
		- Para el Query 4, los vuelos cuyo código OACI era del estilo "N/A" o "AR-####" o "SA##" o no era un código OACI común,
		ejemplo "FAA EJERCITO ARGENTINO", fueron todos agrupados en los movimientos con aeropuertos desconocidos. 
		Estos se expresan de la forma:
			CODIGO_OACI;;#;#
		- El espacio en blanco entre dos ";" simboliza que el campo desconocido.
	5.2 - Algunas consideraciones respecto de los archivos:
		- Los archivos .csv que el programa va a leer tienen que estar dentro de la carpeta "Datasets".
		- El archivo con los aeropuertos tiene que llamarse "archivoAeropuertos.csv".
		- El archivo con los vuelos tiene que llamarse "archivoVuelos.csv".
		- Si se desea utilizar otro nombre de archivo o moverlos de lugar, hay que modificar el 
		código en el archivo "ProcessData.c", y escribir el file path relativo al Current Working Directory de los archivos.
		- Los archivos tienen que tener el formato especificado en la consigna, sino los datos van a ser erroneos.
		
------------------------------------------------------------------------------------------------------------------------------------------

6 - Información extra:
	- Origen de la formula del cálculo del día de la semana:
		- http://gmmentalgym.blogspot.com/2011/03/day-of-week-for-any-date-revised.html#ndatebasics
		- https://lifehacker.com/5848651/how-to-quickly-figure-out-the-day-of-the-week-any-date-falls-on

------------------------------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
