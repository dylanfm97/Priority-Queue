CXXFLAGS := -std=c++11 -g
CXX := g++
TARGETS := main

main: main.o pq.o
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp pq.h
	$(CXX) $(CXXFLAGS) -c $<
pq.o: pq.cpp pq.h

clean:
	rm -f $(TARGETS)
	rm -f *.o *~