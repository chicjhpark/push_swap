# Push_swap
### Introduction
- 스택에 있는 데이터를 한정된 명령어를 이용하여 최대한 적은 횟수 내에 정렬하는 프로그램입니다.
```
$> make
$> make bonus
```
![push_swap_example](https://user-images.githubusercontent.com/69841779/211346679-b9c99729-1195-4250-8815-c831906d6f04.gif)
### Checker
![checker_example2](https://user-images.githubusercontent.com/69841779/211349374-f7dae3a8-1c4a-421a-bd9a-c9f93fdd83a6.gif)
> ctrl-D 키를 눌러 입력을 마칠 수 있습니다.

![checker_directions](https://user-images.githubusercontent.com/69841779/211348830-76d5bb33-ea4e-41d2-aea0-3ad9ca283c07.gif)
### Rules
- 프로그램의 목표는 스택 a에 정수들을 오름차순으로 정렬하는 것입니다.
- 목표를 달성하기 위해서 다음과 같은 명령어를 사용합니다.
```
sa : swap a - 스택 a의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 a가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
sb : swap b - 스택 b의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 b가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
ss - sa와 sb를 동시에 수행합니다.
pa : push a - 스택 b의 top에 위치한 원소 한 개를 스택 a의 top으로 옮깁니다. 스택 b가 비어있을 경우에는 아무 동작도 하지 않습니다.
pb : push b - 스택 a의 top에 위치한 원소 한 개를 스택 b의 top으로 옮깁니다. 스택 a가 비어있을 경우에는 아무 동작도 하지 않습니다.
ra : rotate a - 스택 a의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
rb : rotate b - 스택 b의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
rr : ra와 rb를 동시에 수행합니다.
rra : reverse rotate a - 스택 a의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
rrb : reverse rotate b - 스택 b의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
rrr : rra와 rrb를 동시에 수행합니다.
```
### Development Report
1. 기존에 있는 알고리즘을 참고하지 않고 주어진 명령어만을 이용하여 스택의 앞뒤 숫자를 비교해가면서 정렬해 가며 b스택으로 옮기는 식으로 했다. 적은 숫자가 들어왔을 땐 효율이 나왔지만 많은 숫자가 들어오니 효율적이지 못 했다.
2. 퀵 정렬을 참고하여 중간 값이 되는 1개의 피벗을 두고 정렬을 했으나 이 또한 많은 숫자가 들어오면 효율적이지 못 했다.
3. 피벗을 이용하지만 1개가 아닌 중간 값이 되는 2개의 피벗을 정해서 정렬을 했다. 예를 들어 1~100이라는 숫자가 들어왔다면 33과 66을 피벗으로 정하고 정렬을 했다.
<img width="397" alt="스크린샷 2023-01-16 오후 7 16 12" src="https://user-images.githubusercontent.com/69841779/212654155-88357574-da63-468a-860e-ad898c806455.png">
