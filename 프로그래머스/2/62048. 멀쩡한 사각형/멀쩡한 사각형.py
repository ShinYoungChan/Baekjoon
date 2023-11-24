def gcd(a,b):
    return b if a % b == 0 else gcd(b,a%b)

def solution(w,h):
    answer = w*h - (w+h-gcd(w,h))
    return answer