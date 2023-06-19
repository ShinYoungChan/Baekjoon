import re

large = input()
search = input()
large = re.sub(r'[0-9]+','',large)

if search in large:
    print("1")
else:
    print("0")