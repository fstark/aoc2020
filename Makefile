test: go
	sort -n input.txt | ./go

go: main.cpp
	g++ -std=c++17 main.cpp -lc++ -o go

clean:
	@rm -f go
