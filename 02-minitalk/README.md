# 1. minitalk

|           |                                       |
| :-------: | ------------------------------------- |
|   Topic   | Inter Process Communication, TCP, UTF |
|  Related  | Operating Systems, Computer Network   |
|   Stack   | C                                     |
| Evaluated | 2021-08-02                            |

<br/>

# 2. Summary

minitalk 프로젝트는 UNIX signal을 이용하여 소규모 데이터 교환 프로그램을 구현하는 것이다.

<br/>

# 3. What I learned

유닉스 시그널을 활용한 프로세스간 통신과 UTF-8 등 문자의 인코딩에 대해 학습하였다. 또한 `signal`, `sigaction` 함수들에 대해 숙달하였다. 본 프로젝트에 대한 세부정보와 선행지식은 [Link](https://efilevol42.oopy.io/50cc0257-793e-4462-87ec-71fe0d21e1fc)에 정리하였다.

<br/>

# 4. Features

- `server` 와 `client` 두개의 프로그램을 통해 텍스트를 통신한다.

- `server`는 재시작할 필요 없이 다수의 `client`로부터 텍스트를 연속적으로 수신할 수 있다.

- `server` 와 `client` 두개의 프로그램은 `SIGUSR1`과 `SIGUSR2` 두개의 `UNIX Signal`을 활용하여 통신한다.

- 1000개의 문자(char)를 전송하는데 대략 0.7초가 소요된다.

- 해당 통신과정에서 소규모 ACK 시스템에 의해, 비트단위로 메세지의 송수신을 검사하여 통신의 무결성을 보장한다.

- 해당 통신과정에서 인코딩 방식은 UTF-8을 사용하며, 유니코드를 지원한다.

<br/>

# 5. Demo

![minitalk demo](https://user-images.githubusercontent.com/83692797/131014999-63b90ad0-6cb3-4553-8a90-8683a337447b.gif)

<br/>

# 6. Flow Chart

![minitalk flowchart](https://user-images.githubusercontent.com/83692797/128640437-a1e778b7-3381-4148-b38f-3ec9a8e92c86.png)

<br/>

# 7. How to compile the project

본 프로젝트의 결과물은 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)를 지원한다. 모든 소스코드들이 컴파일된 후에 프로그램이 생성된다.

- For both server and client
  > make all

<br/>

# 8. How to execute the program

다음과 같은 절차로 `server`와 `client`는 텍스트를 통신한다.

1. `server`와 `client` 중 `server`가 먼저 실행되어야 하며, `server`는 실행 시 자신의 `PID`를 출력한다. `server`는 `client`의 `PID`를 입력받을 때까지 대기한다.

> ./server

2. `client`는 다음과 같은 명령어를 통해 `server`의 `PID`와 송신하고자 하는 메제지와 함께 실행되어야 하며, `client`는 실행 시 자신의 `PID`를 출력한다.

> ./client \<server_pid> \<message to send>

3. 메세지 수신을 위해 대기중인 `server` 프로그램에 `client`의 `PID`를 입력한다.

4. `server`는 수신한 메세지를 출력하고, 다음 수신을 위해 대기한다.
