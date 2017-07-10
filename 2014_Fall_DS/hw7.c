#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
#include<stdbool.h>

struct Map {
		char city[100];
} map[30];

int num,d[30],m[30][30],edge[30][30],visit[30],parent[30];

void getPat(char *temp ,char *pat1 ,char *pat2 ,char *pat3) {
		memset(pat1,'\0',1000);
		memset(pat2,'\0',1000);
		memset(pat3,'\0',1000);
		while(!isspace(*temp)) {
				*pat1++ = *temp++;
		}
		while(isspace(*temp)) {
				*temp++;
		}
		while(!isspace(*temp)) {
				*pat2++ = *temp++;
		}
		while(isspace(*temp)) {
				*temp++;
		}
		while(!isspace(*temp)) {
				*pat3++ = *temp++;
		}
}

int searchMap(char *pat) {
		int i;
		for(i=0 ;i<30 ;i++) {
				if(strcmp(map[i].city,pat) == 0) {
						return i;
				}
		}
		return -1;
}

void buildMap(char *pat1 ,char *pat2 ,char *pat3) {
		int i,j,k;
		if((i = searchMap(pat1)) == -1) {
				i = num++;
				strcpy(map[i].city,pat1);
		}
		if((j = searchMap(pat2)) == -1) {
				j = num++;
				strcpy(map[j].city,pat2);
		}
		k = atoi(pat3);
		m[i][j] = k;
		m[j][i] = k;
}

void resetData() {
		int i;
		for(i=0 ;i<30 ;i++) {
				d[i] = 1 << 30;
				visit[i] = 0;
				parent[i] = -1;
		}
}

void DFS(int i) {
		visit[i] = 1;
		printf("%s\n",map[i].city);
		int j;
		for(j=0 ;j<30 ;j++) {
				if(m[i][j] != -1 && visit[j] != 1) {
						DFS(j);
				}
		}
}

void BFS(int i) {
		int j,k,que[30];
		for(j=0 ;j<30 ;j++) {
				que[j] = -1;
		}
		j = 0;
		k = 0;
		que[j++] = i;
		visit[i] = 1;
		while(que[k] != -1) {
				int l;
				for(l=0 ;l<30 ;l++) {
						if(m[que[k]][l] != -1 && visit[l] != 1) {
								visit[l] = 1;
								que[j++] = l;
						}
				}
				k++;
		}
		for(k=0 ;k<j ;k++) {
				printf("%s\n",map[que[k]].city);
		}
}

void SP(int i) {
		visit[i] = 1;
		int k;
		for(k=0 ;k<30 ;k++) {
				if(i == k) continue;
				if(visit[k] != 1 && m[i][k] != -1) {
						if(d[i] + m[i][k] < d[k]) {
								d[k] = d[i] + m[i][k];
								parent[k] = i;
						}
						SP(k);
				}
		}
		visit[i] = 0;
}

void printPath(int i) {
		if(parent[i] != -1) {
				printPath(parent[i]);
				printf("->%s",map[i].city);
		}
		else {
				printf("%s",map[i].city);
		}
}

int checkedge(int a) {
		int i,j;
		for(i=0 ;i<num ;i++) {
				if(i==a) continue;
				if(parent[i]==-1) return 1;
		}
		return 0;
}

void eSP(int i) {
		visit[i] = 1;
		int k;
		for(k=0 ;k<30 ;k++) {
				if(i == k) continue;
				if(visit[k] != 1 && edge[i][k] == 1) {
								parent[k] = i;
						eSP(k);
				}
		}
		visit[i] = 0;
}

void MST() {
		int i,j;
		for(i=0 ;i<30 ;i++) {
				for(j=0 ;j<30 ;j++) {
						if(m[i][j] != -1) edge[i][j] = 0;
						else edge[i][j] = -1;
				}
		}
		int a,b;
		resetData();
		while(checkedge(a)) {
				int min = 1 << 30;
				for(i=0 ;i<num ;i++) {
						for(j=i+1 ;j<num ;j++) {
								if(m[i][j] < min && edge[i][j] == 0) {
										a = i;
										b = j;
										min = m[i][j];
								}
						}
				}
				if(edge[a][b] == 1) break;
				resetData();
				eSP(a);
				if(parent[b] == -1) {
						printf("%*s%*s%*d\n",'\t',map[a].city,'\t',map[b].city,'\t',m[a][b]);
				}
				edge[a][b] = 1;
				edge[b][a] = 1;
		}
}

int main(int argc,char **argv) {

		int i,j;
		for(i=0 ;i<30 ;i++) {
				for(j=0 ;j<30 ;j++) {
						m[i][j] = -1;
				}
		}

		FILE *fp;
		fp = fopen(argv[1],"r");
		if(!fp) {
				puts("Error: File not found.");
				return 0;
		}

		num = 0;
		char temp[1000];
		while(fgets(temp,1000,fp) != NULL) {
				char pat1[1000],pat2[1000],pat3[1000];
				getPat(temp,pat1,pat2,pat3);
				buildMap(pat1,pat2,pat3);
		}

		printf("usr->");
		while(fgets(temp,1000,stdin) != NULL) {
				char pat1[1000],pat2[1000],pat3[1000];
				getPat(temp,pat1,pat2,pat3);
				if(strcmp(pat1,"DFS") == 0) {
						resetData();
						DFS(searchMap(pat2));
				}
				else if(strcmp(pat1,"BFS") == 0) {
						resetData();
						BFS(searchMap(pat2));
				}
				else if(strcmp(pat1,"SP") == 0) {
						resetData();
						d[searchMap(pat2)] = 0;
						SP(searchMap(pat2));
						printf("minimum cost: %d\n",d[searchMap(pat3)]);
						printPath(searchMap(pat3));
						printf("\n");
				}
				else if(strcmp(pat1,"MST") == 0) {
						MST();
				}
				else if(strcmp(pat1,"q") == 0){
						return 0;
				}
				else {
				}
				printf("usr->");
		}

		return 0;
}
