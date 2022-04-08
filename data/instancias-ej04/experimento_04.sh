#bin/usr/bash
mkdir -p ../output-ej04
for i in interval_instance_*
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/ej04 < $i > ../output-ej04/$i.output
    done