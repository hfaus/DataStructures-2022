Graph Representation Cont.

(a)-(c)-(b)
|    |   |      bi-directional edge 
(d)-(e)-(f)

1. Adjacency Matrix
    Ex- Adjacency Matrix
        a b c d
        a i 5 1 i
        b 5 i 7 4
        c 1 7 i 2
        d i 4 2 i

        'i' stands for the infinity symbol

2. Adjacency Lists 
    |a| -> c -> d
    |b| -> c -> f
    |c| -> a -> b -> e
    |d| -> a -> e
    |e| -> c -> d -> f
    |f| -> b -> e

    Ex- Adjacency Lists
        |a| -> b,5 -> c,1
        |b| -> a,5 -> c,7 -> d,4
        |c| -> a,1 -> b,7 -> d,2
        |d| -> b,4 -> c,2

3. Weighted Graphs
    (a)-5-(b)
    |    / |
    1  /7  4
    |/     |
    (c)-2-(d)

4. Cycle
    a-c 
    | |
    b-d 

    A path of positive length that starts and ends at the same vertex and does not 
    traverse the same edge more than once.

    a-c-d-b-a OR a-b-d-c-a represent the cycle above

5. Acyclic Graph
        (a)
         |
    (d)-(b)-(c)
         |
        (e)

    A graph with no cycles.

6. Connected Graph
    A graph where every pair of its vertices 'u' and 'v' those is a path from u to v.

7. Tree/Free Tree 
    A connected acyclic graph.

    (a)-(b)
     |
    (c)-(d)
     |
    (e)-(f)
        /
       (g)

    Examples:
    [Free Tree]
        (i)     (d)
         |       |
        (c)-(b)-(a)-(e)
         |   |       |
        (h) (g)     (f)

    [Rooted Tree] - A tree with a root
            (a)
            /|\
         (b)(d)(e)
         /\     |
       (c)(g)  (f)
       /\
     (h)(i)
     'a' -> the root node 
     b,d,e -> siblings
     c -> descendant of 'a'
     a -> ancestor of 'c'
     b -> child of 'a'
    [Ordered Tree]
        A rooted tree in which all the children are ordered 
    [Binary Tree]
        A rooted tree in which each vertex has no more than 2 children.
            (a)
            /
          (b)
          /\
        (c)(d)
        /\   \
      (h)(g)  (e)
       \       /
       (i)   (f)

8. Forest
    (a)-(b)   (e)
     |   |     |
    (c) (d)   (f)-(g)

    A graph with no cycles but not necessarily connected.

9. Digraph
    (a)->(c)<-(b)
     ^   |^    |
     |   *|    *
    (d)->(e)->(f)

    * is the arrow head for a down arrow
