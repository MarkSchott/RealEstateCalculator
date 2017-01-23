INCDIRS = -I include/.
LIB = -lm
ALL = main.x

default: $(ALL)

%.o: %.cpp
	g++ -c -Wall $< -o $@ $(INCDIRS)

%.x: %.o 
	g++ $< -Wall $(LIB) -o $@

clean:
	/bin/rm -f *.x *.o *~