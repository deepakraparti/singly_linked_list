TARGET:app

app:app.o libsll.a
	gcc app.o -o app -Llib -lsll

app.o:app.c
	gcc -c -I lib/ app.c -o app.o

libsll.a:sll.o
	ar rs lib/libsll.a lib/sll.o

sll.o:lib/sll.c
	gcc -c -I lib/ lib/sll.c -o lib/sll.o

clean:
	rm lib/sll.o
	rm lib/libsll.a
	rm app.o
	rm app

