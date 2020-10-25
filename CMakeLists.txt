cmake_minimum_required(VERSION 3.17)
project(LogicExpressionChecker C)

set(CMAKE_C_STANDARD 99)

add_executable(LogicExpressionChecker

        main.c

        #"DataStructure-Algorithms/Unit Test/Tests/Tests.c"

        "DataStructure-Algorithms/Unit Test/CuTest"
        "DataStructure-Algorithms/Unit Test/CuTest/CuTest.c"
        "DataStructure-Algorithms/Unit Test/CuTest/CuTest.h"
        #"DataStructure-Algorithms/Unit Test/CuTest/AllTests.c"
        #"DataStructure-Algorithms/Unit Test/CuTest/CuTestTest.c"
        #"DataStructure-Algorithms/Unit Test/ErrorsTestStruct.h"

        DataStructure-Algorithms/DataStructure/Stacks/Sources/Stack.c
        DataStructure-Algorithms/DataStructure/Stacks/Headers/Stack.h

        DataStructure-Algorithms/DataStructure/LinkedLists/Sources/LinkedList.c
        DataStructure-Algorithms/DataStructure/LinkedLists/Headers/LinkedList.h

        DataStructure-Algorithms/DataStructure/LinkedLists/Sources/DoublyLinkedList.c
        DataStructure-Algorithms/DataStructure/LinkedLists/Headers/DoublyLinkedList.h

        DataStructure-Algorithms/DataStructure/Strings/Sources/String.c
        DataStructure-Algorithms/DataStructure/Strings/Headers/String.h

        DataStructure-Algorithms/DataStructure/Lists/Sources/ArrayList.c
        DataStructure-Algorithms/DataStructure/Lists/Headers/ArrayList.h

        DataStructure-Algorithms/DataStructure/Lists/Sources/Vector.c
        DataStructure-Algorithms/DataStructure/Lists/Headers/Vector.h

        DataStructure-Algorithms/DataStructure/Lists/Sources/Set.c
        DataStructure-Algorithms/DataStructure/Lists/Headers/Set.h

        DataStructure-Algorithms/DataStructure/Stacks/Sources/DLinkedListStack.c
        DataStructure-Algorithms/DataStructure/Stacks/Headers/DLinkedListStack.h

        DataStructure-Algorithms/DataStructure/Queues/Sources/LinkedListQueue.c
        DataStructure-Algorithms/DataStructure/Queues/Headers/LinkedListQueue.h

        DataStructure-Algorithms/DataStructure/Queues/Sources/Queue.c
        DataStructure-Algorithms/DataStructure/Queues/Headers/Queue.h

        DataStructure-Algorithms/DataStructure/Trees/Sources/BinaryTree.c
        DataStructure-Algorithms/DataStructure/Trees/Headers/BinaryTree.h

        DataStructure-Algorithms/DataStructure/Trees/Sources/AVLTree.c
        DataStructure-Algorithms/DataStructure/Trees/Headers/AVLTree.h

        DataStructure-Algorithms/DataStructure/Trees/Sources/SplayTree.c
        DataStructure-Algorithms/DataStructure/Trees/Headers/SplayTree.h

        DataStructure-Algorithms/System/Utils.h

        DataStructure-Algorithms/DataStructure/Trees/Sources/Trie.c
        DataStructure-Algorithms/DataStructure/Trees/Headers/Trie.h

        DataStructure-Algorithms/DataStructure/Queues/Sources/StackQueue.c
        DataStructure-Algorithms/DataStructure/Queues/Headers/StackQueue.h

        DataStructure-Algorithms/DataStructure/Tables/Sources/HashMap.c
        DataStructure-Algorithms/DataStructure/Tables/Headers/HashMap.h

        DataStructure-Algorithms/DataStructure/Queues/Sources/PriorityQueue.c
        DataStructure-Algorithms/DataStructure/Queues/Headers/PriorityQueue.h

        DataStructure-Algorithms/DataStructure/Queues/Sources/HPriorityQueue.c
        DataStructure-Algorithms/DataStructure/Queues/Headers/HPriorityQueue.h

        DataStructure-Algorithms/DataStructure/Tables/Sources/LinkedListHashMap.c
        DataStructure-Algorithms/DataStructure/Tables/Headers/LinkedListHashMap.h

        DataStructure-Algorithms/DataStructure/Trees/Sources/RedBlackTree.c
        DataStructure-Algorithms/DataStructure/Trees/Headers/RedBlackTree.h

        DataStructure-Algorithms/DataStructure/Trees/Sources/BinaryHeap.c
        DataStructure-Algorithms/DataStructure/Trees/Headers/BinaryHeap.h

        DataStructure-Algorithms/DataStructure/Tables/Sources/HashSet.c
        DataStructure-Algorithms/DataStructure/Tables/Headers/HashSet.h

        DataStructure-Algorithms/DataStructure/Graphs/Sources/DirectedGraph.c
        DataStructure-Algorithms/DataStructure/Graphs/Headers/DirectedGraph.h

        DataStructure-Algorithms/DataStructure/Deque/Sources/Deque.c
        DataStructure-Algorithms/DataStructure/Deque/Headers/Deque.h

        DataStructure-Algorithms/DataStructure/Graphs/Sources/UndirectedGraph.c
        DataStructure-Algorithms/DataStructure/Graphs/Headers/UndirectedGraph.h

        DataStructure-Algorithms/DataStructure/Deque/Sources/DLinkedListDeque.c
        DataStructure-Algorithms/DataStructure/Deque/Headers/DLinkedListDeque.h


        DataStructure-Algorithms/DataStructure/Matrices/Sources/Matrix.c
        DataStructure-Algorithms/DataStructure/Matrices/Headers/Matrix.h

        DataStructure-Algorithms/DataStructure/Pairs/Sources/Pair.c
        DataStructure-Algorithms/DataStructure/Pairs/Headers/Pair.h

        DataStructure-Algorithms/FilesHandler/Sources/TxtFileLoader.c
        DataStructure-Algorithms/FilesHandler/Headers/TxtFileLoader.h

        DataStructure-Algorithms/FilesHandler/Sources/InputScanner.c
        DataStructure-Algorithms/FilesHandler/Headers/InputScanner.h

        DataStructure-Algorithms/Algorithms/Sorting/Headers/Sorting.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/BubbleSort.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/BubbleSort.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/SwapFunction.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/SwapFunction.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/SelectionSort.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/SelectionSort.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/InsertionSort.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/InsertionSort.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/MergeSort.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/MergeSort.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/QuickSort.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/QuickSort.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/CountingSort.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/CountingSort.h
        DataStructure-Algorithms/Algorithms/Sorting/Sources/HeapSort.c
        DataStructure-Algorithms/Algorithms/Sorting/Headers/HeapSort.h

        DataStructure-Algorithms/Algorithms/Searching/Headers/Searching.h
        DataStructure-Algorithms/Algorithms/Searching/Sources/LinearSearch.c
        DataStructure-Algorithms/Algorithms/Searching/Headers/LinearSearch.h
        DataStructure-Algorithms/Algorithms/Searching/Sources/BinarySearch.c
        DataStructure-Algorithms/Algorithms/Searching/Headers/BinarySearch.h
        DataStructure-Algorithms/Algorithms/Searching/Sources/TernarySearch.c
        DataStructure-Algorithms/Algorithms/Searching/Headers/TernarySearch.h
        DataStructure-Algorithms/Algorithms/Searching/Sources/JumpSearch.c
        DataStructure-Algorithms/Algorithms/Searching/Headers/JumpSearch.h
        DataStructure-Algorithms/Algorithms/Searching/Sources/ExponentialSearch.c
        DataStructure-Algorithms/Algorithms/Searching/Headers/ExponentialSearch.h

        DataStructure-Algorithms/Algorithms/ArraysAlg/Sources/ArraysAlg.c
        DataStructure-Algorithms/Algorithms/ArraysAlg/Headers/ArraysAlg.h

        DataStructure-Algorithms/Algorithms/ArraysAlg/Sources/CharArrayAlg.c
        DataStructure-Algorithms/Algorithms/ArraysAlg/Headers/CharArrayAlg.h

        DataStructure-Algorithms/Algorithms/IntegersAlg/Sources/IntegerAlg.c
        DataStructure-Algorithms/Algorithms/IntegersAlg/Headers/IntegerAlg.h

        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/ListsTest/VectorTest/VectorTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/ListsTest/VectorTest/VectorTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/ListsTest/VectorTest/VectorTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/ListsTest/ArrayListTest/ArrayListTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/ListsTest/ArrayListTest/ArrayListTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/LinkedListsTest/LinkedListTest/LinkedListTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/LinkedListsTest/LinkedListTest/LinkedListTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/LinkedListsTest/DoublyLinkedListTest/DoublyLinkedListTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/LinkedListsTest/DoublyLinkedListTest/DoublyLinkedListTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/StacksTest/StackTest/StackTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/StacksTest/StackTest/StackTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/StacksTest/DLinkedListStackTest/DLinkedListStackTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/StacksTest/DLinkedListStackTest/DLinkedListStackTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/QueueTest/QueueTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/QueueTest/QueueTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/StackQueueTest/StackQueueTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/StackQueueTest/StackQueueTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/LinkedListQueueTest/LinkedListQueueTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/LinkedListQueueTest/LinkedListQueueTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/PriorityQueueTest/PriorityQueueTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/PriorityQueueTest/PriorityQueueTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/DequesTest/DequeTest/DequeTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/DequesTest/DequeTest/DequeTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/DequesTest/DoublyLinkedListDequeTest/DoublyLinkedListDequeTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/DequesTest/DoublyLinkedListDequeTest/DoublyLinkedListDequeTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/MatricesTest/MatrixTest/MatrixTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/MatricesTest/MatrixTest/MatrixTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/StringsTest/StringTest/StringTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/StringsTest/StringTest/StringTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TablesTest/HashMapTest/HashMapTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TablesTest/HashMapTest/HashMapTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TablesTest/DounlyLinkedListHashMapTest/DoublyLinkedListHashMapTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TablesTest/DounlyLinkedListHashMapTest/DoublyLinkedListHashMapTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TablesTest/HashSetTest/HashSetTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TablesTest/HashSetTest/HashSetTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/GraphsTest/DirectedGraphTest/DirectedGraphTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/GraphsTest/DirectedGraphTest/DirectedGraphTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/GraphsTest/UndirectedGraphTest/UndirectedGraphTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/GraphsTest/UndirectedGraphTest/UndirectedGraphTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/TrieTest/TrieTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/TrieTest/TrieTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/RedBlackTreeTest/RedBlackTreeTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/RedBlackTreeTest/RedBlackTreeTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/SortAlgTests/SortAlgTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/SortAlgTests/SortAlgTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/SearchAlgTests/SearchAlgTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/SearchAlgTests/SearchAlgTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/IntegerAlgTest/IntegerAlgTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/IntegerAlgTest/IntegerAlgTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/FilesHandlersTests/InputScannerTest/InputScannerTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/FilesHandlersTests/InputScannerTest/InputScannerTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/ArraysAlgTest/ArraysAlgTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/ArraysAlgTest/ArraysAlgTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/FilesHandlersTests/TxtFileLoaderTest/TxtFileLoaderTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/FilesHandlersTests/TxtFileLoaderTest/TxtFileLoaderTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/CharArrayAlgTest/CharArrayAlgTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/AlgorithmsTests/CharArrayAlgTest/CharArrayAlgTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/BinaryTreeTest/BinaryTreeTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/BinaryTreeTest/BinaryTreeTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/BinaryHeapTest/BinaryHeapTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/BinaryHeapTest/BinaryHeapTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/AVLTreeTest/AVLTreeTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/AVLTreeTest/AVLTreeTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/SplayTreeTest/SplayTreeTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/TreesTest/SplayTreeTest/SplayTreeTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/PairsTest/PairTest/PairTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/PairsTest/PairTest/PairTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/HeapPriorityQueueTest/HeapPriorityQueueTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/QueuesTest/HeapPriorityQueueTest/HeapPriorityQueueTest.h"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/ListsTest/SetTest/SetTest.c"
        "DataStructure-Algorithms/Unit Test/Tests/DataStructuresTests/ListsTest/SetTest/SetTest.h"

        LogixInfixCalculator.c LogixInfixCalculator.h)