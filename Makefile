test: go
	# cat input.txt | sed -e 's/x/0/g' | sed -e 's/,/ /g' | ./go
	python3 main.py

go: main.cpp
	g++ -std=c++17 main.cpp -lc++ -o go

clean:
	@rm -f go
