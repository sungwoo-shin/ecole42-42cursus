# 1. ft_printf(FSM ver.)

|           |                                       |
| :-------: | ------------------------------------- |
|   Topic   | Finite State Machine                  |
|  Related  | Automata Theory, Discrete Mathematics |
|   Stack   | C                                     |
| Evaluated | 2021-10-11                            |

<br/>

# 2. Refactoring

|                                        Version                                         |   Date   | Improvements                                                                       |
| :------------------------------------------------------------------------------------: | :------: | ---------------------------------------------------------------------------------- |
| [ver1](https://github.com/24siefil/42SEOUL-42cursus/tree/main/01-ft_printf) → FSM ver. | 21-10-11 | Automata 이론의 Finite State Machine을 활용하여 새롭게 풀이, 반환값 관련 구조 개선 |

<br/>

# 3. Summary

본 레포지토리는 복잡한 조건문을 통해 구현한 ft_printf 프로젝트를, Automata 이론의 Finite-State Machine을 활용하여 리팩토링한 결과물이다. ft_printf 프로젝트는 `printf` 함수를 직접 구현하는 것이다. 구현하는 함수의 프로토타입은 다음과 같다.

```c
int ft_printf(const char *format);
```

<br/>

# 4. What I learned

Automata 이론의 Finite-State Machine을 적용하는 Design Process에 대해 학습하였다. 또한 이를 활용한 복잡한 구문분석(Parsing), 입력과 예외처리에 대해 숙달하였다. 본 프로젝트에 대한 세부정보와 선행지식은 [Link](https://efilevol42.oopy.io/3ba55797-9476-43c9-ae66-1e57dd8059e4)에 정리하였다.

<br/>

# 5. Features

- 구현한 `ft_printf` 함수의 사용법은 `<stdio.h>`의 `printf`와 동일하며, 가변인자를 통한 서식지정자 사용을 지원한다. 사용가능한 서식지정자는 다음과 같다.

|           |                                     |
| --------- | ----------------------------------- |
| Flag      | `-` `0`                             |
| Width     | `<numbers>` `*`                     |
| Precision | `.<numbers>` `.*`                   |
| Type      | `c` `s` `p` `d` `i` `u` `x` `X` `%` |

- `ft_printf` 함수는 주어진 문자열을 출력하기 위해 동적 메모리 할당을 사용하지 않는다. 따라서 버퍼 관리 기능은 지원하지 않는다.
- 본 프로젝트 결과물은 `f`, `F`, `e`, `E`, `g`, `G` 옵션은 지원하지 않는다.
- 입력과 예외처리를 위해 Mealy Machine이 활용된다.

<br/>

# 6. State transition diagram

![ft_printf State Transition Table](https://user-images.githubusercontent.com/83692797/136704738-cf7b21c1-6a7a-4ece-8317-339bd9a35ad9.png)

<br/>

# 7. State transition table

|     |  %   | 1 ~ 9 | NULL |  .   |  \*  |  -   |  0   | type | % 외 |
| :-: | :--: | :---: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
|  0  |  2   |   1   |  10  |  1   |  1   |  1   |  1   |  1   |  1   |
|  1  |  2   |   1   |  10  |  1   |  1   |  1   |  1   |  1   |  1   |
|  2  |  8   |   3   |  -1  |  5   |  4   |  2   |  2   |  8   |  -1  |
|  3  |  8   |   3   |  -1  |  5   |  -1  |  -1  |  3   |  8   |  -1  |
|  4  |  8   |  -1   |  -1  |  5   |  -1  |  -1  |  -1  |  8   |  -1  |
|  5  |  8   |   6   |  -1  |  -1  |  7   |  -1  |  6   |  8   |  -1  |
|  6  |  8   |   6   |  -1  |  -1  |  -1  |  -1  |  6   |  8   |  -1  |
|  7  |  8   |  -1   |  -1  |  -1  |  -1  |  -1  |  -1  |  8   |  -1  |
|  8  | FIN. | FIN.  | FIN. | FIN. | FIN. | FIN. | FIN. | FIN. | FIN. |
| 10  | FIN. | FIN.  | FIN. | FIN. | FIN. | FIN. | FIN. | FIN. | FIN. |

<br/>

# 8. Flow chart

![ft_printf flowchart drawio](https://user-images.githubusercontent.com/83692797/136706659-5aacdb7f-3ac4-4418-ad0c-e6da3ec61bed.png)

<br/>

# 9. How to compile the project

본 프로젝트의 결과물은 정적 라이브러리를 생성하는 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)와 `bonus` rule을 지원한다.

- For the Mandatory
  > make all
- For the Bonus
  > make bonus

<br/>

# 10. How to include the static library

외부 프로젝트에서, 본 프로젝트의 결과물인 정적 라이브러리를 활용하고자 할 때는 다음 명령어를 사용한다.

> gcc -Wall -Werror -Wextra -L \<directory-name> -l \<library-name>

정적 라이브러리의 이름은 `lib`로 시작해야 하며 `.a`로 끝나야 한다. 또한 \<library-name>은 `lib`와 `.a`를 제외한 형태이어야 한다. 정적 라이브러리 이름을 `libftprintf.a`로 한다면 \<library-name>은 `ftprintf`이어야 한다.
