test: go
	./go

go: main.cpp
	g++ -O4 -std=c++17 main.cpp -lc++ -o go

clean:
	@rm -f go
