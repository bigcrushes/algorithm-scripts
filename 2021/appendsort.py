# Round 1A Append Sort answer
T = int(input())
for kk in range(1, T + 1):
    answer = 0
    N = int(input())
    numbers = input().split()
    for i in range(1, N):
        if int(numbers[i]) > int(numbers[i-1]):
            continue
        else:
            if len(numbers[i]) == len(numbers[i-1]):
                numbers[i] += '0'
                answer += 1
            else:
                front_bigger = False
                front_smaller = False
                len_diff = len(numbers[i - 1]) - len(numbers[i])
                for j in range(len(numbers[i])):
                    if(numbers[i][j] > numbers[i-1][j]):
                        front_bigger = True
                        break
                    else:
                        if(numbers[i][j] < numbers[i-1][j]):
                            front_smaller = True
                            break
                if front_bigger:
                    for temp in range(len_diff):
                        answer += 1
                        numbers[i] += '0'
                elif front_smaller:
                    for temp in range(len_diff + 1):
                        answer += 1
                        numbers[i] += '0'
                else:
                    all_nines= True
                    for temp in range(len(numbers[i]), len(numbers[i-1])):
                        if numbers[i-1][temp] != '9':
                            all_nines = False
                    if all_nines:
                        for temp in range(len_diff + 1):
                            answer += 1
                            numbers[i] += '0'
                    else:
                        ini_len = len(numbers[i])
                        numbers[i] = str(int(numbers[i-1]) + 1)
                        answer += len(numbers[i]) - ini_len
                    
    print(f"Case #{kk}:", answer)
                
                
