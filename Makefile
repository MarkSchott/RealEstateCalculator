INCDIRS = -I include/
LIB = -lm
ALL = main.x
OBJS = main.o Values.o

default: $(ALL)

%.o: %.cpp
	g++ -c -Wall $< -o $@ $(INCDIRS)	

%.x: $(OBJS) 
	g++ $^ -Wall $(LIB) -o $@

clean:
	/bin/rm -f *.x *.o *~
