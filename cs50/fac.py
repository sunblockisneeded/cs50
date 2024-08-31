def factorial(): #함수 정의
    result = 1
    for i in range(num, 0, -1):
            result *= i
    print(f"{num}! => {result}")

while True: #무조건실행, while 문을 반복함
    num = int(input("정수 입력 : "))
    if num == 0:
        print("factorial End.")
        break
    factorial()
