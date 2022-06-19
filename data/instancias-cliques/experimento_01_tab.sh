#bin/usr/bash
mkdir -p ../output-cliques-02
slash=' \\'
ands=' && '

echo '\begin{center}
\begin{tabular}{ c r } 
Instancia & Tiempo (seg.) \\
\hline'
for i in *.clq
    do
	filename=${i//_/\\_}
	time=$(/usr/bin/time -f "%e" timeout 600 ../../src/backtracking_02 < $i)
	echo $filename$ands$time$slash
    done
echo '\end{tabular}
\end{center}'
