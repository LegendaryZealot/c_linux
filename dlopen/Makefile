all : 
	gcc -fPIC -shared -Wl,-E caculate.c -o libcaculate.so 
	gcc -rdynamic -o app main.c -ldl
clean :
	-rm -f libcaculate.so *.o app 
# all : 
# 	gcc -fPIC -shared -Wl,-E caculate.c -o libcaculate.so   //-Wl,-E for call func int mother programe by so
# 	gcc -rdynamic -o app main.c -ldl
# clean :
# 	-rm -f libcaculate.so *.o app 