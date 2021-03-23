# Google Code Jam 2020 Round 1A Pattern Matching answer
testcases = int(input())
for i in range(testcases):
  patterns = int(input())
  start = []
  max_start = 0
  longest_start = ""
  end = []
  max_end = 0
  longest_end = ""
  all_patterns = []
  impossible = False
  answer = ""
  for j in range(patterns):
    pattern_list = input().split('*')
    if pattern_list[0] != '':
      start.append(pattern_list[0])
      if len(pattern_list[0]) > max_start:
        max_start = len(pattern_list[0])
        longest_start = pattern_list[0]  
      pattern_list.pop(0)
    if pattern_list and pattern_list[-1] != '':
      end.append(pattern_list[-1])
      if max_end < len(pattern_list[-1]):
        longest_end = pattern_list[-1]
        max_end = len(pattern_list[-1])
      pattern_list.pop(-1)
    new_pattern = ''.join(pattern_list)
    all_patterns.append(new_pattern)
  for starters in start:
    if starters == longest_start[0:len(starters)]:
      continue
    else:
      impossible = True
      continue
  if impossible:
    print(f"Case #{str(i + 1)}: *")    
    continue
  answer += longest_start
  for strings in all_patterns:
    answer += strings
  for enders in end:
    if enders == longest_end[-len(enders):]:
      continue
    else:
      impossible = True
      continue
  if impossible:
    print(f"Case #{str(i + 1)}: *") 
    continue
  answer += longest_end
  print(f"Case #{str(i + 1)}: {answer}")
  
  

    
