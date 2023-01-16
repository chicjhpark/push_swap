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

