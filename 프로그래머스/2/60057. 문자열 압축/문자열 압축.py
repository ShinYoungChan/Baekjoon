def solution(s):
    answer = 0
    length = len(s)//1
    result=[]
    if length == 1:
        return 1
    for i in range(1,length):
        strList=[]
        for j in range(0,len(s),i):
            strList.append(s[j:j+i])
    
        result.append(strList)
    
    ans = []
    for i in range(len(result)):
        count = 1
        qqq=""
        index=0
        for j in range(len(result[i])-1):
            index = j
            if result[i][j]==result[i][j+1]:
                count += 1
            else:
                if count != 1:
                    qqq+=str(count)+result[i][j]
                else:
                    qqq+=result[i][j]
                count=1
        if count != 1:
            qqq+=str(count)+result[i][index]
        else:
            qqq+=result[i][index+1]
        ans.append(len(qqq))
                    
        
    return min(ans)