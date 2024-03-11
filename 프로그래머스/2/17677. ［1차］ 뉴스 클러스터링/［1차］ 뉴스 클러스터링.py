import re

def solution(str1, str2):
    answer = 0
    str1 = [str1[i:i+2].upper() for i in range(0, len(str1)-1) if not re.findall('[^a-zA-Z]+', str1[i:i+2])]
    str2 = [str2[i:i+2].upper() for i in range(0, len(str2)-1) if not re.findall('[^a-zA-Z]+', str2[i:i+2])]
    intersection = []
    union = []
    intersection = set(str1) & set(str2)
    union = set(str1) | set(str2)
    intersection = sum([min(str1.count(i),str2.count(i))for i in intersection])
    union = sum([max(str1.count(i),str2.count(i)) for i in union])
    if not intersection and not union:
        return 65536
    return int(intersection/union*65536)