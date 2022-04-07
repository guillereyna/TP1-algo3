#bin/usr/bash
for i in *.clq
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/backtracking01 < $i > ../output-cliques-01/$i.output
    done