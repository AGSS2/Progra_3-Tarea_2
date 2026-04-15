Integrantes:
-
Adrian Valentino Gamboa Rodriguez

Funcionamiento:
-
El archivo test.cpp esta diseñado para ejecutarse una vez y hacer pruebas con los algoritmos creados.
En estas pruebas se puede comprobar los tipos de datos que son aceptados y los que no debido a los concept de Divisible, Addable e Iterable
Entre los resultados podemos observar:
- Los datos de tipo "int" y "double" dentro de un vector son aceptados por los concepts utilizados
- Los datos de tipo "string" y "char" no son validos por el concept Divisible que no cumple con esta condición
- Los datos que no esten en formato vector no seran aceptados por el concept Iterable que rechaza datos sueltos sin tamaño
