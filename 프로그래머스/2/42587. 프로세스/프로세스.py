from collections import deque

def solution(priorities, location):
    queue = deque()
    for i in range(len(priorities)):
        if i == location:
            queue.append((priorities[i],True))
        else:
            queue.append((priorities[i],False))
    answer = 0
    while len(queue)!=0:
        data = queue.popleft()
        rotate = False
        for i in range(len(queue)):
            if queue[i][0] > data[0]:
                queue.append(data)
                rotate = True
                break
        if not rotate:
            answer+=1
            if data[1]:
                break
    return answer