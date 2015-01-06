GCC = gcc
DATA = deque.c

all: lru lfu sc random
run10: lru10 lfu10 sc10 random10
run50: lru50 lfu50 sc50 random50
run100: lru100 lfu100 sc100 random100
run150: lru150 lfu150 sc150 random150
run200: lru200 lfu200 sc200 random200
run250: lru250 lfu250 sc250 random250
run300: lru300 lfu300 sc300 random300
run350: lru350 lfu350 sc350 random350
run400: lru400 lfu400 sc400 random400
run450: lru450 lfu450 sc450 random450
run500: lru500 lfu500 sc500 random500

lru: lru.c $(DATA)
	$(GCC) -Wall -o lru lru.c $(DATA)
lfu: lfu.c $(DATA)
	$(GCC) -Wall -o lfu lfu.c $(DATA)
sc: 2chance.c $(DATA)
	$(GCC) -Wall -o sc 2chance.c $(DATA)
random: random.c $(DATA)
	$(GCC) -Wall -o random random.c $(DATA)

lru10: lru 10.txt
	cat 10.txt | ./lru 100
lfu10: lfu 10.txt
	cat 10.txt | ./lfu 100
sc10: sc 10.txt
	cat 10.txt | ./sc 100
random10: random 10.txt
	cat 10.txt | ./random 100

lru50: lru 50.txt
	cat 50.txt | ./lru 100
lfu50: lfu 50.txt
	cat 50.txt | ./lfu 100
sc50: sc 50.txt
	cat 50.txt | ./sc 100
random50: random 50.txt
	cat 50.txt | ./random 100

lru100: lru 100.txt
	cat 100.txt | ./lru 100
lfu100: lfu 100.txt
	cat 100.txt | ./lfu 100
sc100: sc 100.txt
	cat 100.txt | ./sc 100
random100: random 100.txt
	cat 100.txt | ./random 100

lru150: lru 150.txt
	cat 150.txt | ./lru 100
lfu150: lfu 150.txt
	cat 150.txt | ./lfu 100
sc150: sc 150.txt
	cat 150.txt | ./sc 100
random150: random 150.txt
	cat 150.txt | ./random 100

lru200: lru 200.txt
	cat 200.txt | ./lru 100
lfu200: lfu 200.txt
	cat 200.txt | ./lfu 100
sc200: sc 200.txt
	cat 200.txt | ./sc 100
random200: random 200.txt
	cat 200.txt | ./random 100

lru250: lru 250.txt
	cat 250.txt | ./lru 100
lfu250: lfu 250.txt
	cat 250.txt | ./lfu 100
sc250: sc 250.txt
	cat 250.txt | ./sc 100
random250: random 250.txt
	cat 250.txt | ./random 100

lru300: lru 300.txt
	cat 300.txt | ./lru 100
lfu300: lfu 300.txt
	cat 300.txt | ./lfu 100
sc300: sc 300.txt
	cat 300.txt | ./sc 100
random300: random 300.txt
	cat 300.txt | ./random 100

lru350: lru 350.txt
	cat 350.txt | ./lru 100
lfu350: lfu 350.txt
	cat 350.txt | ./lfu 100
sc350: sc 350.txt
	cat 350.txt | ./sc 100
random350: random 350.txt
	cat 350.txt | ./random 100

lru400: lru 400.txt
	cat 400.txt | ./lru 100
lfu400: lfu 400.txt
	cat 400.txt | ./lfu 100
sc400: sc 400.txt
	cat 400.txt | ./sc 100
random400: random 400.txt
	cat 400.txt | ./random 100

lru450: lru 450.txt
	cat 450.txt | ./lru 100
lfu450: lfu 450.txt
	cat 450.txt | ./lfu 100
sc450: sc 450.txt
	cat 450.txt | ./sc 100
random450: random 450.txt
	cat 450.txt | ./random 100

lru500: lru 500.txt
	cat 500.txt | ./lru 100
lfu500: lfu 500.txt
	cat 500.txt | ./lfu 100
sc500: sc 500.txt
	cat 500.txt | ./sc 100
random500: random 500.txt
	cat 500.txt | ./random 100

clean: rm -rf lru lfu sc random

