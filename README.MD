Trabajo práctico 1 de Algoritmos y Estructuras de Datos 3. Primer cuatrimestre del 2022.

Facultad de Ciencias Exactas y Naturales de la UBA.

### Compilación y ejecución:

Para compilar los binarios de todos los ejercicios, utilizar el siguiente comando en el directorio actual:

```bash
make all
```

Para correr todos los experimentos, ejecutar el siguiente comando en el directorio actual:

```bash
bash experimentos.sh > tiempos.txt
```
Los tiempos de ejecución de todas las instancias se encontrarán en el archivo `tiempos.txt`.

El output de cada instancia se encontrará en el directorio `data/` en su carpeta `output-*/` correspondiente como un archivo `*.output`.

#### Ejecución y experimentación sobre instancias y ejercicios particulares

En el directorio `data/` se encuentran directorios `instancias-*` que contienen archivos de instancias para cada problema.

Ejemplo de ejecución sobre una instancia particular:

```bash
./src/backtracking_01 < data/instancias-cliques/brock200-3.clq
```

Para correr un experimento sobre todas las instancias de un problema, se debe correr el bash script correspondiente al problema en el directorio de instancias de ese problema. Por ejemplo, para el problema 1 de backtracking:

```bash
cd data/instancias-cliques
bash experimento01.sh
```

Esto devuelve los resultados por salida estándard y deja el output de cada instancia en el directorio `data/output-cliques-01`.

### Integrantes:

Guillermo José Reyna Maciel, LU 393/20  
Marco Aurelio Sanchez Sorondo, LU 708/19
Casado Farall, Joaquín, LU 072/20
Chumacero, Carlos Nechemias, LU 492/20
Vitali, Lucas, LU 278/20