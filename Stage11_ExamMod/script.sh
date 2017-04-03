if [ "$1" == "-c" ]; then
	yacc -d -v stg5_1.y
	lex stg5_1.l
	gcc -w y.tab.c lex.yy.c
	./a.out ./$2
else
	./a.out ./$1
fi
cd labelTranslation/
./a.out out1.xsm
cd ../../xsm_expl_new
echo "Running the Machine Code"
./xsm -l lib.xsm -e out2.xsm
