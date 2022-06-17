#bin/usr/bash
mkdir -p ../output-cliques-02
for i in *.clq
    do
        echo "Experimento $i"
        /usr/bin/time -f "%e" timeout 6000 ../../src/backtracking_02 < $i
    done
