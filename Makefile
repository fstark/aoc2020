test: go
	cat input.txt | sed -e 's/\(,[0-9]*\)$$/\1,-1/g' | ./go

go: main.cpp
	g++ -O3 -std=c++17 main.cpp -lc++ -o go

clean:
	@rm -f go
