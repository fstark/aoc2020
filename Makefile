go: main.cpp
	g++ -std=c++17 main.cpp -lc++ -o go
	./go < input.txt

clean:
	@rm -f go
