#bin/usr/bash
for i in ./data/instancias-ej04/*
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ./src/ej04 < $i
    done