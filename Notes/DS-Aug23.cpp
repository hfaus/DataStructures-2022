Fundamentals of Algorithmic Problem Solving
    #1 Understanding the problem
    #2 Ascertain the capabilities of the computational device
        - RAM 
        - Speed and space
    #3 Choose between exact vs. approximate problem solving
    #4 Design the algorithm and choose the appropriate data structure
    #5 Prove the correctness of the algorithm
    #6 Analyze the algorithm 
        - Time efficency
        - Space efficency
    #7 Coding the algorithm

Problem types
    #1 Searching 
    #2 Sorting
    #3 Geometric
    #4 Combinatorial
    #5 Graph

Fundamental data structures
    #1 Array 
        - List of values
        - Access by index
        - Advantages:
            * Same access time for any array element
            * Stored contiguously in memory and values are accessed by its index
    #2 Linked list
        - Data and pointer
        - Item[0] & pointer -> [point to] the next Item[1] & pointer
            * Single-Linked list
        - null & Item[0] & pointer <-> pointer & Item[1] & pointer <-> pointer & Item[2] & pointer <-> ...
            * Double-Linked list
        - Advantages:
            * No need to allocate contiguous memory like that of an array
            * Memory is allocated as values get added to a linked list
            * Easy to add and remove, just make sure pointers line up correctly
        - Disadvantages:
            * Searching through a linked list is slower as it always begins at the head
    #3 Stack
        - LIFO order (Last in first out)
        - Push() and Pop()
        (Ex) Push(1), Push(2), Push(3), Pop()
            -> 3 is deleted
    #4 Queue
        - FIFO order (First in first out)
        - Enqueue() and Dequeue()
        (Ex) Enqueue(1), Enqueue(2), Enqueue(3), Dequeue()
            -> 1 is deleted

Graphs
    G = <V,E>
        V = vertices
        E = edges

    Undirected graph:
        (u)------(v)

        Loop:
            <---|
            (u)-|
            - Edges that connect vertices ot themselves

        - For an undirected graph with no loops, 0 <= |E| <= |V|(|V| - 1) / 2

            (u)--(v)
             \   /
              (w)
    
    Sparse graph:
        - A graph with relatively few edges when compared to the number of vertices

    Dense graph:
        - A graph with only a few missing edges
    
    Complete graph:
        - A graph with every pain of vertices connected by an edge

    [Graph representation]

        (a)-(c)-(b)
        |    |   |
        (d)-(e)-(f)

        Adjacency matrix:
          a b c d e f
        a 0 0 1 1 0 0
        b 0 0 1 0 0 1
        c 1 1 0 0 1 0
        d 1 0 0 0 1 0
        e 0 0 1 1 0 1
        f 0 1 0 0 1 0

