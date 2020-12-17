test: go
	cat input.txt | ./go

go: main.cpp
	g++ -O3 -std=c++17 main.cpp -lc++ -o go

clean:
	@rm -f go
