all:
	cc main_curl.c siec.c logika.c interpretacja.c -lcurl -o curl ../cJSON/cJSON.o

test:
	./curl move explore move explore rotate_left move explore move explore rotate_right move explore move explore rotate_right explore move explore move explore rotate_right explore move explore move explore rotate_right explore move explore move explore

exp:
	./curl explore rotate_left explore rotate_left explore rotate_left explore rotate_left