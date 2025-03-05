# Max Heap Queue - Getting maximum element from a sorted list
# Use: SORTING
import heapq
 
# Creating empty heap
heap = []
heapq.heapify(heap)
 
# Adding items to the heap using heappush
# function by multiplying them with -1
heapq.heappush(heap, -1 * 10)
heapq.heappush(heap, -1 * 5)
heapq.heappush(heap, -1 * 7)
heapq.heappush(heap, -1 * 400)
 
# printing the value of maximum element
print("Head value of heap: " + str(-1 * heap[0]))
 
# printing the elements of the heap
print("\nThe heap elements: ")
for i in heap:
    print(-1 * i, end = ' ')
print("\n")
 
element = heapq.heappop(heap)
 
# printing the elements of the heap
print("\nThe heap elements: ")
for i in heap:
    print(-1 * i, end = ' ')
print("\n")