all:print.o setCard.o works.o jobActFG.o jobActFN.o jobActRG.o jobActRN.o
		gcc main.c print.o setCard.o works.o jobActFG.o jobActFN.o jobActRG.o jobActRN.o -o main
print:
		gcc -c print.c -o print.o
setCard:
		gcc -c setCard.c -o setCard.o
works:
		gcc -c works.c -o works.o
jobActFG:
		gcc -c jobActFG -o jobActFG.o
jobActFN:
		gcc -c jobActFN -o jobActFN.o
jobActRG:
		gcc -c jobActRG -o jobActRG.o
jobActRN:
		gcc -c jobActRN -o jobActRN.o

