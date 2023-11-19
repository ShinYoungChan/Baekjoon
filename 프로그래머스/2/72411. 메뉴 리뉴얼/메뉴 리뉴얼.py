from itertools import combinations

def solution(orders, course):
    answer = []
    menuList={}
    for c in course:
        for order in orders:
            if len(order) >= c:
                order = sorted(order)
                combi = combinations(order,c)
                for menu in combi:
                    menu = ''.join(menu)
                    if menu in menuList:
                        menuList[menu]+=1
                    else:
                        menuList[menu] = 1
    for key in menuList.keys():
        add = True
        for key2 in menuList.keys():
            if key == key2:
                continue
            if len(key) == len(key2) and menuList[key] < menuList[key2] or menuList[key] == 1:
                add=False
                break
        if add:
            answer.append(key)
            
    answer=list(set(answer))
    answer.sort()
    return answer