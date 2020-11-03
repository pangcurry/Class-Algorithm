# 예시
lst = [chr(i) for i in range(65,91)]
print(lst)
for i in lst:
    print(f"{i} - {hash(i)}")

# 내가 푼 방법
for i in participant:
        if i in completion:
            dlist[i] = True
        else :
            dlist[i] = False

#쌤이 푼 방법
temp = 0
dic = {}

for part in participant:
    dic[hash(part)] = part
    temp += hash(part)

for com in completion:
    temp -= hash(com)

answer = dic[temp]
return answer

# 2번 내가 푼 방법
def solution(phone_book):
    mstr = phone_book[0]
    for i in range(1,len(phone_book)):
        if mstr in phone_book[i]:
            return False
    return True

# 2번 쌤이 푼 방법
answer = True
hash_map = {}

for phone_number in phone_book:
    hash_map[phone_number] = 1
for phone_number in phone_book:
    temp = ""
    for number in phone_number:
        temp += number
        if temp in hash_map and temp != phone_number:
            answer = False
return answer
