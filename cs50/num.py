# 빈 리스트 생성
data_list = []

# 데이터 입력받기
print("10개의 데이터를 입력해주세요.")
for i in range(10):
    data = int(input(f"임의의 값 입력: "))
    data_list.append(data)

# 입력한 값 출력
print(f"입력한 값: {data_list}")

# 짝수만 추출하여 새 리스트에 저장
even_list = [] # 짝수를 담을 빈 리스트 생성
for 고수정 in data_list: # data_list의 각 요소에 대해 반복
    if 고수정 % 2 == 0: # 만약 현재 요소가 짝수라면
        even_list.append(고수정) # even_list에 현재 요소를 추가
        


# 짝수 값 출력
print(f"짝수 값: {even_list}")
