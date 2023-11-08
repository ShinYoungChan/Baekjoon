def solution(s):
    answer = 0
    length=len(s)
    for i in range(length):
        s=s[1:]+s[:1]
        yes = True if s[0]=='{' or s[0]=='[' or s[0]=='(' else False
        stack=[]
        for j in s:
            if j=='{' or j=='['or j=='(':
                stack.append(j)
            else:
                if len(stack)>0:
                    if j==']' and stack[-1]!='[':
                        break
                    elif j==']' and stack[-1]=='[':
                        stack.pop()
                    if j=='}' and stack[-1]!='{':
                        break
                    elif j=='}' and stack[-1]=='{':
                        stack.pop()
                    if j==')' and stack[-1]!='(':
                        break
                    elif j==')' and stack[-1]=='(':
                        stack.pop()
        if len(stack)==0 and yes:
            answer+=1
                    
    return answer