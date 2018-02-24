LIBS=$(wildcard libs/*)	
INCLUDE_PATH=libs/

build: libraries
	c++ main.cpp $(wildcard libraries/*) -I$(INCLUDE_PATH) -o Prime 
	chmod +x Prime

install: libraries
	c++ main.cpp $(wildcard libraries/*) -I$(INCLUDE_PATH) -o Prime
	chmod +x Prime
	cp fermatprime /usr/local/bin

libraries:
	mkdir libraries/
	for dir in $(LIBS); do \
		cd $$dir; \
		g++ -c *.cpp -I../; \
		ls; \
		mv *.o ../../libraries; \
		cd -; \
	done

clean:
	rm -rf libraries/ Prime
