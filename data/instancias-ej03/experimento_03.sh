#bin/usr/bash
echo "Corriendo experimento con implementación top-down"
mkdir -p ../output-ej03-td
for i in instancia_*
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/ej03_td < $i > ../output-ej03-td/$i\_td.output
    done

echo "Corriendo experimento con implementación bottom-up"
mkdir -p ../output-ej03-bu
for i in instancia_*
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/ej03_bu < $i > ../output-ej03-bu/$i\_bu.output
    done