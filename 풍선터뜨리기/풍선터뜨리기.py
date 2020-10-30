def solution(a):

    temp, answer = a[0], 3

    if len(a) <= 2:     #1또는 2 처리
        return len(a)

    least = min(a)      # 배열에서 최솟값 구하기
    least_idx = a.index(least)  # 최솟값 인덱스 구하기
    if a[0] == least or a[-1] == least: #양쪽 끝 최솟값 체크
        answer -= 1

    for i in a[1:least_idx]:    # 최솟값 왼쪽 탐색
        if temp > i:
            answer += 1
            temp = i

    temp = a[-1]    # 가장오른쪽 값 초기화
    for i in a[-2:least_idx:-1]: # 최솟값 오른쪽 탐색
        if temp > i:
            answer += 1
            temp = i

    return answer
