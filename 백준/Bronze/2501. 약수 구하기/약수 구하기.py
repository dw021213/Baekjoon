def divisor(n):
    """
    자연수 n의 모든 약수를 찾아 오름차순으로 정렬된 리스트를 반환합니다.
    """
    div = set()
    # n의 제곱근까지만 탐색하여 효율적으로 약수의 쌍을 찾습니다.
    for d in range(1, int(n ** 0.5) + 1):
        if n % d == 0:
            div.add(d)
            div.add(n // d)
    
    return sorted(list(div))


# 함수 정의와 메인 코드 사이에 두 줄을 띄어 가독성을 높입니다.
N, K = map(int, input().split())

D = divisor(N)

# K번째 약수가 존재하는지 확인하고 결과를 출력합니다.
# 존재하지 않으면 0을 출력합니다.
if K <= len(D):
    print(D[K - 1])
else:
    print(0)