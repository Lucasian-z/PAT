n = int(input())
numsHigh = ["tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"]
numsLow = ["tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"]
res = []
for i in range(0, 169):
    n1 = i // 13
    n2 = i % 13
    if n1 != 0:
        tmp = numsHigh[n1-1]
        if n2 != 0:
            tmp += " " + numsLow[n2]
        res.append(tmp)
    else:
        res.append(numsLow[n2])
for i in  range(0, n):
    str = input()
    if str[0] >= '0' and str[0] <= '9':
        print(res[int(str)])        
    else:
        for idx in range(0, 169):
            if res[idx] == str:
                print(idx)
                break