# PI-TPE
Trabajo practico final para Programacion Imperativa (Primer Cuatrimestre 2018)
Fecha: 12/07/2018

Integrantes:
	Gonzalo Hirsch - 59089
	Francisco Letterio - 58408
	Ignacio Villanueva - 59000
  
Como compilar:
	- Primero moverse dentro del sistema hasta tener como Current Working Directory(CWD) la carpeta donde se encuentran los archivos, en especial el "main.c".
	- Segundo, escribir el comando(el signo "$" indica la terminal):
		$	gcc *.c ./ADT/*.c -o OUTPUT_NAME -Wall -pedantic -std=c99 -fsanitize=address
	Tener en cuenta que OUTPUT_NAME es el nombre con que va a salir el ejecutable del programa, cambielo a gusto(Cumpliendo las normas para nombrar archivos).
	
Como ejecutar(habiendo ya compilado anteriormente):
	- Primero moverse dentro del sistema hasta tener como Current Working Directory(CWD) la carpeta donde se encuentran los archivos.
	- Segundo, escribir el comando(el signo "$" indica la terminal):
		$	./OUTPUT_NAME AÑO_A_ELECCION
	Tener en cuenta que OUTPUT_NAME es el mismo conmbre con que se compiló, y el AÑO_A_ELECCION es un año entre 2014 y 2018.
	
Algunas consideraciones para las estadisticas de los Query:
	- Para el Query 2, los vuelos que en la clasificación del vuelo estaban marcados como "N/A", al no saber si son internacionales o no, fueron contados como internacionales.
	- Para el Query 4, los vuelos cuyo código OACI era del estilo "N/A" o "AR-####" o "SA##" o no era un código oaci comun, ejemplo "FAA EJERCITO ARGENTINO", fueron todos agrupados en los movimientos con aeropuertos desconocidos. Estos se expresan de la forma:
		CODIGO_OACI;;#;#
	El espacio en blanco entre los dos ";" simboliza que es desconocido.
	
Origen de la formula del cálculo del día de la semana:
	- http://gmmentalgym.blogspot.com/2011/03/day-of-week-for-any-date-revised.html#ndatebasics
	- https://lifehacker.com/5848651/how-to-quickly-figure-out-the-day-of-the-week-any-date-falls-on
  
  
