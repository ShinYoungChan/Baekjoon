def solution(enroll, referral, seller, amount):
    answer = []
    en = dict()
    result = dict()
    for i in range(len(enroll)):
        en[enroll[i]] = referral[i]
        result[enroll[i]] = 0
    
    for i in range(len(seller)):
        money = amount[i]*100
        name = seller[i]
        while money != 0 and name != '-':
            result[name] += money - money//10
            money = money // 10
            name = en[name]
    
    for i in result.values():
        answer.append(i)
    
    return answer