# 변수 size개의 th번째 minterm을 구하는 함수
def minterm(size, th):
    return bin(th)[2:].zfill(size)

# 길이가 같은 두 문자열을 비교하여 차이나는 개수를 세는 함수
def diff(a, b):
    ret = 0
    for i in range(len(a)):
        if a[i] != b[i]:
            ret += 1
    return ret

# 차이가 1 나는 문자열 두개를 합치는 함수
def union(a, b):
    for i in range(len(a)):
        if a[i] != b[i]:
            return a[:i] + "-" + b[i+1:]

# minterm들을 비교하여 최적화하는 함수
def optimize(input):
    n = len(input)
    ret = []
    used = [False] * n
    for i in range(n):
        for j in range(i+1, n):
            if diff(input[i], input[j]) == 1:
                ret.append(union(input[i], input[j]))
                used[i] = True
                used[j] = True
    
    for i in range(n):
        if used[i] == False:
            ret.append(input[i])

    return used.count(True) > 0, list(set(ret))
    # return 최적화되었는지, 최적화결과

# 문자열 -> 어떤 minterm으로 구성되어있는지 분해
def decompose(input):
    if input.count('-') == 0:
        return [int(input, 2)]    
    idx = input.find('-')
    return decompose(input[:idx] + '0' + input[idx+1:]) + decompose(input[:idx] + '1' + input[idx+1:])

def solution(input):
    size = input[0]
    n = input[1]
    minterms = [minterm(size, th) for th in input[2:]]

    PI = minterms # Prime Implicant
    changed = True
    while changed:
        changed, PI = optimize(PI)
    
    minterm_cnt = [0] * (2 ** size)

    for term in PI:
        for mi in decompose(term):
            minterm_cnt[mi] += 1

    EPI = []
    NEPI = []
    for term in PI:
        isEPI = False
        for mi in decompose(term):
            if minterm_cnt[mi] == 1:
                isEPI = True
                break
        if isEPI:
            EPI.append(term)
        else:
            NEPI.append(term)

    EPI = sorted(EPI, key=lambda s:s.replace('-','2'))
    NEPI = sorted(NEPI, key=lambda s:s.replace('-','2'))
    return ["EPI"] + EPI + ["NEPI"] + NEPI

if __name__ == '__main__':
    input1 = [3, 4, 0, 1, 2, 3]
    input2 = [3, 6, 0, 1, 2, 5, 6, 7]
    # print(minterm(4, 5))
    # print(diff("000", "110"))
    # print(union("000", "010"))
    # print(decompose("000-"))

    print(solution(input1))
    print(solution(input2))