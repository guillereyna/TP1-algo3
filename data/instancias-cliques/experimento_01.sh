#bin/usr/bash
mkdir -p ../output-cliques-01
for i in *.clq
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/backtracking_01 < $i > ../output-cliques-01/$i.output
    done
