
CC = g++
CFLAGS = -g 
CPPFLAGS =  -O1  

%.o  :  %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@


clean:
	rm *.o


permutation.o : permutation.cpp  



permutation : permutation.o


