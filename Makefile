test: go
	cat input.txt | sed -e 's/\[/ \[/g' | ./go

go: main.cpp
	g++ -std=c++17 main.cpp -lc++ -o go

clean:
	@rm -f go
