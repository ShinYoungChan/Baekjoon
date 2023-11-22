def solution(s):
    answer = []
    s=s.split('{')
    s="".join(s)
    s=s.split('}')
    lis = []
    for element in s:      
        qwe = []
        strNum = ""
        for i in element:
            if i.isdigit():
                strNum+=i
            else:
                if strNum != "":
                    qwe.append(int(strNum))
                strNum = ""
        if strNum != "":
            qwe.append(int(strNum))
        if len(qwe) !=0:
            lis.append(qwe)
    lis.sort(key = lambda x: len(x))
    for lisNum in lis:
        for qqq in lisNum:
            if qqq not in answer:
                answer.append(qqq)
                    
    return answer