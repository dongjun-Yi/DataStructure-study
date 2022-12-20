#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 6
//해당 인덱스 값
typedef struct {
	short r;
	short c;
}element;

element here = { 1,0 }, entry = { 1,0 };

char maze[MAX_SIZE][MAX_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

typedef struct {
	element data[MAX_SIZE];
	int top;
}StackType;

//초기화
void init_stack(StackType* s) {
	s->top = -1;
}

//overflow check 함수
int is_full(StackType* s) {
	return s->top == MAX_SIZE - 1;
}

//undeflow check 함수
int is_empty(StackType* s) {
	return s->top == -1;
}

void push(StackType* s, element item) {
	//overflow check
	if (is_full(s))
		printf("스택 포화 에러\n");

	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	//underflow check
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}

void push_loc(StackType* s, int r, int c) {
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

void maze_print(char maze[MAX_SIZE][MAX_SIZE]) {
	printf("\n");
	for (int r = 0;r < MAX_SIZE;r++) {
		for (int c = 0;c < MAX_SIZE;c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

void main() {
	int r, c;
	StackType s;
	//좌표를 담아둘 배열
	element pathxy[20];
	int cnt = 0;
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != 'x') {
		r = here.r;
		c = here.c;
		maze[r][c] = '.';
		
		maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);

		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else {
			here = pop(&s);
			//스택에서 꺼낸 좌표들을 배열에 저장
			pathxy[cnt++] = here;
		}
	}
	//좌표 출력
	printf("출구부터 입구까지의 경로 좌표 : \n");
	for (int i = 0;i < cnt;i++) {
		if (i == cnt - 1)
			printf("(%d, %d)", pathxy[i].r, pathxy[i].c);
		else
			printf("(%d, %d) ->", pathxy[i].r, pathxy[i].c);
	}
	printf("\n");
	printf("성공\n");
}