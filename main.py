# factors = [7,13,0,0,59,0,31,19]
factors = [29,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,37,0,0,0,0,0,409,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,17,13,19,0,0,0,23,0,0,0,0,0,0,0,353,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,41]

candidate = 0
pos = 1
while factors[pos]==0:
    pos = pos + 1
delta = factors[0]

while True:
    wait = factors[pos]-(candidate%factors[pos])
    # print( "%d:%d (+%d) %d => wait: %d" % ( pos, candidate, delta, factors[pos], wait ) )
    if wait!=pos%factors[pos]:
        candidate += delta
    else:
        # print( "FOUND" )
        delta = delta * factors[pos]
        # print( "DELTA = %d" % delta )

        pos = pos +1
        if pos>=len(factors):
            break
        while factors[pos]==0:
            pos = pos + 1

print( "%d\n" % candidate )
