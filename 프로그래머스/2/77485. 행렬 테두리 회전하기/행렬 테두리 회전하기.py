def solution(rows, columns, queries):
    answer = []
    array = [[i+(columns*j) for i in range(1,columns+1)] for j in range(0,rows)]
    for i in queries:
        x1 = i[0]-1
        y1 = i[1] - 1
        x2 = i[2] -1
        y2 = i[3] - 1
        rotate = (x2-x1+1)*2+(y2 - y1)*2-2
        x = x1
        y = y1
        u,d,l,r=False,False,False,True
        temp = array[x1][y1]
        temp1 = array[x1][y1]
        minNum=[temp]
        for _ in range(rotate):
            if u:
                temp = array[x-1][y]
                array[x-1][y] = temp1
                temp1=temp
                x-=1
            if d:
                temp = array[x+1][y]
                array[x+1][y] = temp1
                temp1=temp
                x+=1
            if l:
                temp = array[x][y-1]
                array[x][y-1] = temp1
                temp1=temp
                y-=1
            if r:
                temp = array[x][y+1]
                array[x][y+1] = temp1
                temp1=temp
                y+=1
            if x == x2 and y==y2:
                u,d,l,r=False,False,True,False
            if x == x1 and y==y1:
                u,d,l,r=False,False,False,True
            if y == y2 and x==x1:
                u,d,l,r=False,True,False,False
            if y == y1 and x==x2:
                u,d,l,r=True,False,False,False
            minNum.append(temp)
        answer.append(min(minNum))
    return answer