from itertools import combinations

def solution(relation):
    answer = 0
    length = len(relation[0])
    item = [i for i in range(length)]
    combiList=[]
    for i in range(length):
        combiList.extend(combinations(item,i+1))
    print(combiList)
    qwe=[]
    combiPossible=[]
    for combi in combiList:
        print(combi)
        lis=[]
        for i in range(len(relation)):
            keyStr = ""
            combiStr=""
            for j in combi:
                keyStr+=relation[i][j]
            lis.append(keyStr)
        candiKey=True
        if len(lis)!=len(set(lis)):
            candiKey=False
        real = True
        if candiKey:
            if len(combiPossible)==0:
                combiPossible.append(combi)
                answer+=1
            else:
                for won in combiPossible:
                    count=0
                    for k in won:
                        if k in combi:
                            count+=1
                    if count==len(won):
                        real=False
                if real:
                    combiPossible.append(combi)
                    answer+=1
    return answer