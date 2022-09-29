#두개의 힙이 필요
# left_heap right_heap
# left_haep은 중간값보다 작은 수가 들어감
# right_heap은  중간값 보다 큰 수가 들어감
# left_heap의 맨 앞의 값이 중간 값이 들어감
# left와 right의 앞 값을 비교하여 바꾸어 줌

import heapq
import sys

n = int(sys.stdin.readline())

leftHeap = []
rightHeap = []

for i in range(n):
    num = int(sys.stdin.readline())

    if len(leftHeap) == len(rightHeap):
        heapq.heappush(leftHeap, -num)
    else:
        heapq.heappush(rightHeap, num)
    
    if rightHeap and rightHeap[0] < -leftHeap[0]:
        leftValue = heapq.heappop(leftHeap)
        rightValue = heapq.heappop(rightHeap)

        heapq.heappush(leftHeap, -rightValue)
        heapq.heappush(rightHeap, -leftValue)
    
    print(-leftHeap[0])