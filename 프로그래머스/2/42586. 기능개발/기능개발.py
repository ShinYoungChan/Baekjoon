import math

def solution(progresses, speeds):
    answer = []
    complete = []
    for p, s in zip(progresses, speeds):
        complete.append(math.ceil((100-p)/s))
    que = [complete.pop(0)]
    for c in complete:
        if que[0] >= c:
            que.append(c)
        else:
            answer.append(len(que))
            que.clear()
            que.append(c)
    answer.append(len(que))
    return answer