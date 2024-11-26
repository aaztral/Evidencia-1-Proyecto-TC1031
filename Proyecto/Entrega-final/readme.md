# Proyecto: ¡El Mejor Equipo de la NFL!
Este es el mejor sitio para guardar toda la información esencial de tus jugadores favoritos de la National Football League, Con una variedad de opciones puedes crear listas de jugadores y sus ratings, puedes ordenas los jugadores por su overall, su velocidad, su fuerza o su agilidad, y de esta forma saber quienes son los mejores. Puedes crear equipos tomando a los mejores jugadores de cada posición en el criterio que tu quieras. Tienes la opción de agregar todos los jugadores que quieras y eliminarlos, te proporcionamos 5 jugadores de cada posición para que comiences. El sitio ideal para usar durante la temporada regular, puedes armar tu mejor equipo de fantasy y ganarle a todos tus amigos. 

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ -std=c++11 main.cpp -o final` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./final` 

## Descripción de las entradas del avance de proyecto
El proyecto usa 3 archivos de texto diferentes, uno para cada posición implementada: 

1. Para la posición de Quarter Back:
QuarterBa.txt contiene 5 jugadores y sus respectivos ratings, estos siguen un orden de: Nombre,overall,velocidad,fuerza,agilidad.
Ejemplo:

Patrick Mahomes,97,87,70,87
Joe Burrow,94,83,68,82
Josh Allen,93,88,80,85
Lamar Jackson,98,95,63,95
Justin Herbert,86,86,71,80

2. Para la posición de Wide Receiver:
WideRec.txt contiene 5 jugadores y sus respectivos ratings, estos siguen un orden de: Nombre,overall,velocidad,fuerza,agilidad.
Ejemplo:

Justin Jefferson,99,92,64,93
Davante Adams,90,90,63,95
Tyreek Hill,98,99,64,98
Stefon Diggs,91,92,62,92
A.J. Brown,95,91,79,86

3. Para la posición de Running Back:
RunningBa.txt contiene 5 jugadores y sus respectivos ratings, estos siguen un orden de: Nombre,overall,velocidad,fuerza,agilidad.
Ejemplo:

Christian McCaffrey,99,91,74,95
Derrick Henry,98,91,87,84
Nick Chubb,93,90,86,83
Saquon Barkley,96,93,81,94
Josh Jacobs,91,89,83,86

Todos los datos fueron sacados de los ratings oficiales del videojuego Madden25

## Descripción de las salidas del avance de proyecto
Se presenta un menú de opciones, tienes la opción de desplegar al mejor jugador, una lista ordenada de todos los jugadores, agregar y eliminar jugadores y por último la opción de construir un equipo de los mejores de acuerdo al criterio seleccionado, todo esto se despliega en el shell. 

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
#### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
El análisis de complejidad se encuentra dentro del código.

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
El análisis de complejidad se encuentra dentro del código.

#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
El análisis de complejidad se encuentra dentro del código.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
Para el sorting simplemente recurrí al algoritmo de ordenamiento más eficiente según lo visto en clase, este es el QuickSort, esto debido a que realmente cualquier algoritmo de ordenamiento sería correcto entonces el más eficiente es la opcíon correcta. Y con ayuda del siguiente video no fue un problema la implementación.

https://youtu.be/PupaczLYxmA?si=Uk2x71qDHAOkdbTp

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Para este proyecto decidí un árbol max heap, esto debido a que el jugador con mejor rating va a ser buscado frecuentemenete, por lo tanto el que tenga un mayor número, y al implementar el Max heap esta busqueda se simplifica a una de O(1), ya que el max-heap siempre pone al mayor por delante. 

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
La información se consulta correctamente, esta está ordenada de manera muys simple en un vector playerlist, toda esta información se consulta de manera muy clara desde el menú interactivo.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el proyecto lee 3 archivos distintos para cargar los datos de las estructuras, uno indicado para cada posición donde almacenamos los datos del nombre, overall, velocidad y fuerza. 

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Si lograste este criterio anteriormente, copia aquí tu argumentación. Si no, ésta es una nueva oportunidad para lograrlo. Escribe aquí tu aprendizaje y tus argumentos sobre por qué consideras que ahora ya has desarrrollado este criterio y dónde se puede observar el desarrollo que mencionas.