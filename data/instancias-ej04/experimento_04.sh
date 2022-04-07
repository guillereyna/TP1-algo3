#bin/usr/bash
for i in interval_instance_*
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/ej04 < $i > output-$i
    done