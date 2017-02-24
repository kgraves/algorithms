BSORT=sorting/bubble_sort/bubble_sort
BST=data_structures/binary_search_tree/bst
ISORT=sorting/insertion_sort/insertion_sort
LLIST=data_structures/linked_list/linked_list
SIEVE=math/sieve_of_eratosthenes/sieve
STACK=data_structures/stack/stack
QUEUE=data_structures/queue/queue

all: data_structures math sorting

data_structures: $(BST).cpp $(LLIST).cpp $(LLIST).go $(STACK).cpp $(QUEUE).cpp $(QUEUE).go
	g++ -o $(BST).out $(BST).cpp
	g++ -o $(LLIST).out $(LLIST).cpp
	go build -o $(LLIST)-go $(LLIST).go
	g++ -o $(STACK).out $(STACK).cpp
	g++ -o $(QUEUE).out $(QUEUE).cpp
	go build -o $(QUEUE)-go $(QUEUE).go

math: $(SIEVE).cpp
	g++ -o $(SIEVE).out $(SIEVE).cpp

sorting: $(BSORT).cpp $(ISORT).cpp
	g++ -o $(BSORT).out $(BSORT).cpp
	g++ -o $(ISORT).out $(ISORT).cpp

clean: clean_data_structures clean_math clean_sorting
	rm -f */**/a.out

clean_data_structures:
	rm -f $(BST) $(LLIST) $(LLIST)-go $(STACK) $(QUEUE) $(QUEUE)-go

clean_math:
	rm -f $(SIEVE)

clean_sorting:
	rm -f $(BSORT) $(ISORT)
