#bin/usr/bash
for i in instancia_*
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/ej03 < $i > ../output-ej03/$i.output
    done