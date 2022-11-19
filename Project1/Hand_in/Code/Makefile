obj =  myVector.o structure.o file.o menu.o rand.o reg.o main.o
target = main
CC = g++ 

$(target) : $(obj)

	   $(CC) $(obj) -o $(target)

%.o :%.cpp
	   $(CC) $< -c -o $@ -g

clean:
	   rm *.o main

play:
		 ./main