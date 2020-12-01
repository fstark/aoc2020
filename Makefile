go: main.cpp
	g++ -std=c++17 main.cpp -lc++ -o go
	./go < 01a.txt

clean:
	@rm -f go
