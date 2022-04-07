#/usr/bin/bash
DIR=$( pwd )

echo "Corriendo experimento 1..."
cd "$DIR/data/instancias-cliques/"
bash experimento_01.sh

echo "Corriendo experimento 2..."
cd "$DIR/data/instancias-cliques/"
bash experimento_02.sh

echo "Corriendo experimento 3..."
cd "$DIR/data/instancias-ej03/"
bash experimento_03.sh

echo "Corriendo experimento 4..."
cd "$DIR/data/instancias-ej04"
bash experimento_04.sh

echo "Experimentos terminados. Se puede encontrar el output de cada experimento en data/output-*/ ."