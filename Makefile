test:
#  go
	# (cat input.txt ; echo ; echo "END" ) | tr '\012' '!' | sed -e 's/!!/@/g' | sed -e 's/!/ /g' | sed -e 's/  / /g' | sed -e 's/@/ DONE@/g' | tr '@' '\012' | tr ':' ' ' | ./go
	( echo "ibase=2" ; cat input.txt | tr 'FBLR' '0101' | sort | tail -1 ) | bc

go: main.cpp
	g++ -std=c++17 main.cpp -lc++ -o go

clean:
	@rm -f go
