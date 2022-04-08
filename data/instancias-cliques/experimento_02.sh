#bin/usr/bash
mkdir -p ../output-cliques-02
for i in *.clq
    do
        echo "Procesando $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/backtracking01 < $i > ../output-cliques-02/$i.output
    done