# 1. FdF

|           |                                               |
| :-------: | --------------------------------------------- |
|   Topic   | Line Drawing Algorithms, Isometric Projection |
|  Related  | Computer Graphics, Algorithms & Analysis      |
|   Stack   | C                                             |
| Evaluated | 2021-08-17                                    |

<br/>

# 2. Summary

FdF 프로젝트는 3차원 segment의 점들을 연결하여, 굴곡진 지형을 투영하는 wireframe graphics model을 구현하는 것이다.

<br/>

# 3. What I learned

본 프로젝트를 통해 rotation matrix, linear interpolation, Bresenham’s algorithm, isometric projection 등 graphics의 기본에 대해 학습했다. 또한 기본적인 그래픽스 프로그래밍에 대해 숙달하였다. 본 프로젝트에 대한 세부정보와 선행지식은 [Link](https://efilevol42.oopy.io/51cc984d-995c-4009-9ab2-07924d17815e)에 정리하였다.

<br/>

# 4. Features

- `fdf` 프로그램은 고도(좌표)와 색상 정보를 매개변수(map_file.fdf)로 입력 받는다.
- Segment의 점 투영 시 isometric projection을 사용합니다.
- Segment의 점들 연결 시 Bresenham’s algorithm을 사용합니다.
- 색상 정보가 없는 좌표(픽셀)에 대해서는 linear interpolation을 활용하여 적절한 색상을 부여합니다.
- `fdf` 프로그램 작동중 오류 발생 시 `perror` 함수를 통해 적절한 오류 메세지를 출력한다.
- Ecole 42에서 제작한 그래픽스 라이브러리인 `MiniLibX`를 활용한다.
- `fdf` 프로그램 실행 시 조작법을 화면 좌측에 함께 투영한다.

<br/>

# 5. Demo

- **Demo Video |** https://youtu.be/8J623sq0LjI

![image](https://user-images.githubusercontent.com/83692797/148332120-335756c9-8b1f-4a05-94a4-342545d56971.png)

![image](https://user-images.githubusercontent.com/83692797/148332189-0f977d8f-e8a2-4e45-878b-40ee74487878.png)

![image](https://user-images.githubusercontent.com/83692797/148332224-157f5e0b-fcef-411b-ab20-3e1d0de9a4ab.png)

<br/>

# 6. Flow Chart

![FdF flowchart](https://user-images.githubusercontent.com/83692797/138420514-13bf31e7-75c1-4258-9c95-da53e211e143.png)

<br/>

# 7. How to compile the project

본 프로젝트의 결과물은 `Makefile`을 포함한다. 해당 `Makefile`은 common rules(`all`, `clean`, `fclean`, `re`)를 지원한다. 모든 소스코드들이 컴파일된 후에 프로그램이 생성된다.

- For both Mandatory and Bonus
  > make all

<br/>

# 8. How to execute the program

- `fdf` 프로그램은 투영할 지형의 좌표와 색 정보를 파일형태로 프로그램의 매개변수로 전달받는다.

> ./fdf \<map_file>
