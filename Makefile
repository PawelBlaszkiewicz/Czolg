all: program proba proba_png

program: main_curl.c
	cc main.c siec.c logika.c interpretacja.c obrazek.c -lcurl -lpng -o main ../cJSON/cJSON.o

proba: proba.c
	cc proba.c -o proba -lcurl ../cJSON/cJSON.o

proba_png: proba3.c
	cc proba3.c obrazek.c -lpng -o proba3

swiat: program
	./main mapa.txt minecraft_tiles.png mapa_swiata.png

pamiec: program
	valgrind ./main mapa.txt minecraft_tiles.png mapa_swiata.png 

fun: program
	./main mapa.txt bloczki.png mapa_swiata2.png 

test_cjson : 
	valgrind ./proba

test_png :
	./proba3 proba3_mapa_png.txt minecraft_tiles.png proba3_png.png