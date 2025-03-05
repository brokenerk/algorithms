# Min Heap Queue - Getting minimum element from a sorted list
# Use: SORTING
import heapq
  
# Creating empty heap 
heap = [] 
heapq.heapify(heap) 
  
# Adding items to the heap using heappush function 
heapq.heappush(heap, 10) 
heapq.heappush(heap, 5) 
heapq.heappush(heap, 7) 
heapq.heappush(heap, 400) 
  
# printing the value of minimum element 
print("Head value of heap: ", heap[0]) 
  
# printing the elements of the heap 
print("\nThe heap elements: ")
print(heap)
  
element = heapq.heappop(heap) 
  
# printing the elements of the heap 
print("\nThe heap elements: ")
print(heap)
