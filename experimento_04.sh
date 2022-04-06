for i in ./data/instancias_ej04/
do
    echo "Procesando $i"
    /usr/bin/time -f "%e" timeout 600 ./src/ej04 < $i > $i.output
done