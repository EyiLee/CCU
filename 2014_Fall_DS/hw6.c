#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct keyCount {
		int cnt;
		char *keyWord;
		struct keyCount *left;
		struct keyCount *right;
		struct keyCount *prev;
};

void replaceNode(struct keyCount *bst_ptr ,struct keyCount *node) {
		bst_ptr->cnt = node->cnt;
		free(bst_ptr->keyWord);
		bst_ptr->keyWord = (char *)malloc(sizeof(node->keyWord));
		strcpy(bst_ptr->keyWord,node->keyWord);
		if(node->prev != NULL) {
				if(node == node->prev->left) {
						node->prev->left = NULL;
				}
				if(node == node->prev->right) {
						node->prev->right = NULL;
				}
		}
		free(node);
}

struct keyCount *firstLeaf(struct keyCount *bst_ptr) {
		if(bst_ptr->left == NULL) {
				return bst_ptr;
		}
		while(bst_ptr !=NULL) {
				if(bst_ptr->left != NULL) {
						bst_ptr = bst_ptr->left;
						continue;
				}
				if(bst_ptr->right != NULL) {
						bst_ptr = bst_ptr->right;
						continue;
				}
				break;
		}
		return bst_ptr;
}

struct keyCount *lastLeaf(struct keyCount *bst_ptr) {
		if(bst_ptr->right == NULL) {
				return bst_ptr;
		}
		while(bst_ptr !=NULL) {
				if(bst_ptr->right != NULL) {
						bst_ptr = bst_ptr->right;
						continue;
				}
				if(bst_ptr->left != NULL) {
						bst_ptr = bst_ptr->left;
						continue;
				}
				break;
		}
		return bst_ptr;
}

void buildTree(FILE *fp ,struct keyCount *bst_head) {

		char keyRead[1024];
		struct keyCount *bst_ptr = bst_head;

		while(fgets(keyRead,1024,fp) != NULL) {

				int opr;
				if(keyRead[0] == '+') {
						opr = 1;
				}
				else if(keyRead[0] == '-') {
						opr = -1;
				}
				else {
						puts("Undefined Operator.");
						continue;
				}
				strcpy(keyRead,&keyRead[1]);
				keyRead[strlen(keyRead)-1] = '\0';

				if(bst_ptr->keyWord == NULL) {
						if(opr == -1) {
								printf("keyWord \"%s\" doesn't exist.\n",keyRead);
								continue;
						}
						bst_ptr->cnt = opr;
						bst_ptr->keyWord = (char *)malloc(sizeof(char)*strlen(keyRead)+1);
						strcpy(bst_ptr->keyWord,keyRead);	
						continue;
				}

				while(bst_ptr != NULL) {
						if(strcmp(keyRead,bst_ptr->keyWord) == 0) {
								bst_ptr->cnt += opr;
								break;
						}
						else if(strcmp(keyRead,bst_ptr->keyWord) < 0) {
								if(bst_ptr->left == NULL) {
										bst_ptr->left = (struct keyCount *)malloc(sizeof(struct keyCount));
										bst_ptr->left->keyWord = (char *)malloc(sizeof(keyRead));
										bst_ptr->left->cnt = opr;
										strcpy(bst_ptr->left->keyWord,keyRead);
										bst_ptr->left->prev = bst_ptr;		//set back
										bst_ptr = bst_ptr->left;
										break;
								}
								else {
										bst_ptr = bst_ptr->left;
								}
						}
						else if(strcmp(keyRead,bst_ptr->keyWord) > 0) {
								if(bst_ptr->right == NULL) {
										bst_ptr->right = (struct keyCount *)malloc(sizeof(struct keyCount));
										bst_ptr->right->keyWord = (char *)malloc(sizeof(keyRead));
										bst_ptr->right->cnt = opr;
										strcpy(bst_ptr->right->keyWord,keyRead);
										bst_ptr->right->prev = bst_ptr;		//set back
										bst_ptr = bst_ptr->right;
										break;
								}
								else {
										bst_ptr = bst_ptr->right;
								}
						}
				}

				if(bst_ptr->cnt < 0) {
						printf("keyWord \"%s\" doesn't exist.\n",bst_ptr->keyWord);
				}
				if(bst_ptr->cnt <= 0) {
						if(bst_ptr->left != NULL) {
								if(bst_ptr->left == lastLeaf(bst_ptr->left)) {
										bst_ptr->cnt = bst_ptr->left->cnt;
										free(bst_ptr->keyWord);
										bst_ptr->keyWord = (char *)malloc(sizeof(bst_ptr->left->keyWord));
										strcpy(bst_ptr->keyWord,bst_ptr->left->keyWord);
										if(bst_ptr->left->left != NULL) {
												bst_ptr->left->left->prev = bst_ptr;
												//free(bst_ptr->left);
												bst_ptr->left = bst_ptr->left->left;
										}
										else {
												//free(bst_ptr->left);
												bst_ptr->left = bst_ptr->left->left;
										}
								}
								else {
										replaceNode(bst_ptr,lastLeaf(bst_ptr->left));
								}
						}
						else if(bst_ptr->right != NULL) {
								if(bst_ptr->right == firstLeaf(bst_ptr->right)) {
										bst_ptr->cnt = bst_ptr->right->cnt;
										free(bst_ptr->keyWord);
										bst_ptr->keyWord = (char *)malloc(sizeof(bst_ptr->right->keyWord));
										strcpy(bst_ptr->keyWord,bst_ptr->right->keyWord);
										if(bst_ptr->right->right != NULL) {
												bst_ptr->right->right->prev = bst_ptr;
												//free(bst_ptr->right);
												bst_ptr->right = bst_ptr->right->right;
										}
										else {
												//free(bst_ptr->right);
												bst_ptr->right = bst_ptr->right->right;
										}
								}
								else {
										replaceNode(bst_ptr,firstLeaf(bst_ptr->right));
								}
						}
						else if(bst_ptr == bst_head) {
								free(bst_ptr->keyWord);
								bst_ptr->keyWord = NULL;
						}
						else {
								if(bst_ptr == bst_ptr->prev->left) {
										bst_ptr->prev->left = NULL;
										free(bst_ptr);
								}
								else if(bst_ptr == bst_ptr->prev->right) {
										bst_ptr->prev->right = NULL;
										free(bst_ptr);
								}
						}
				}

				bst_ptr = bst_head;
		}
}

struct keyCount *buildsortTree(struct keyCount *bst_sort ,struct keyCount *bst_ptr,struct keyCount *bst_sort_h){
		if(bst_ptr != NULL) {
				buildsortTree(bst_sort_h,bst_ptr->left,bst_sort_h);
				while(bst_sort != NULL) {
						if(bst_sort->cnt < bst_ptr->cnt) {
								if(bst_sort->left == NULL) {
										bst_sort->left = (struct keyCount *)malloc(sizeof(struct keyCount));
										bst_sort->left->keyWord = (char *)malloc(sizeof(char)*strlen(bst_ptr->keyWord)+1);
										bst_sort->left->prev = bst_sort;
										bst_sort->left->cnt = bst_ptr->cnt;
										strcpy(bst_sort->left->keyWord,bst_ptr->keyWord);
										break;
								}
								else {
										bst_sort = bst_sort->left;
								}
						}
						else if(bst_sort->cnt >= bst_ptr->cnt) {
								if(bst_sort->right == NULL) {
										bst_sort->right = (struct keyCount *)malloc(sizeof(struct keyCount));
										bst_sort->right->keyWord = (char *)malloc(sizeof(char)*strlen(bst_ptr->keyWord)+1);
										bst_sort->right->prev = bst_sort;
										bst_sort->right->cnt = bst_ptr->cnt;
										strcpy(bst_sort->right->keyWord,bst_ptr->keyWord);
										break;
								}
								else {
										bst_sort = bst_sort->right;
								}
						}
				}
				buildsortTree(bst_sort_h,bst_ptr->right,bst_sort_h);
		}
		return bst_ptr;
}

void printTree(struct keyCount *bst_ptr) {
		if(bst_ptr != NULL) {
				printTree(bst_ptr->left);
				if(bst_ptr->keyWord != NULL) {
						printf("%d %s\n",bst_ptr->cnt,bst_ptr->keyWord);
				}
				printTree(bst_ptr->right);
		}
}

char *getpart(char *pat) {
		char *tmp=pat;
		while(isspace(*pat)) {
				pat++;
		}
		strcpy(tmp,pat);
		pat = tmp;
		while(!isspace(*tmp)) {
				tmp++;
		}
		tmp = '\0';
		return pat;

}

void findTree(struct keyCount *bst_ptr ,char *pat) {
		while(bst_ptr != NULL) {
				if(strcmp(bst_ptr->keyWord,pat) > 0) {
						bst_ptr = bst_ptr->left;
				}
				else if(strcmp(bst_ptr->keyWord,pat) < 0) {
						bst_ptr = bst_ptr->right;
				}
				else if(strcmp(bst_ptr->keyWord,pat) == 0) {
						printf("%d %s\n",bst_ptr->cnt,bst_ptr->keyWord);
						break;
				}
		}
		if(bst_ptr == NULL) {
				printf("pattern not found.\n");
		}
}

int main(int argc,char **argv) {
		struct keyCount *bst_head;
		bst_head = (struct keyCount *)malloc(sizeof(struct keyCount));		//initialize BST

 		int i;
 		if(argc <= 1) {
				puts("Error: File not found.");
				return 0;
		}
 		for(i=1 ;i<argc ;i++) {
 				FILE *fp;
				fp = fopen(argv[i],"r");
				if(!fp) {
						puts("Error: File not found.");
						return 0;
				}
				buildTree(fp,bst_head);
				fclose(fp);
		}
		
		struct keyCount *bst_sort = NULL;
		bst_sort = (struct keyCount *)malloc(sizeof(struct keyCount));		//initialize BST
		bst_sort->keyWord = NULL;
		if(bst_head->keyWord != NULL) {
				bst_sort->cnt = bst_head->cnt;
				buildsortTree(bst_sort,bst_head,bst_sort);		//sort bst_head to bsr_sort
		}
		else {
				puts("File is empty.");
				return 0;
		}

		printf("usr ->");
		char oprs[32];
		while(fgets(oprs,32,stdin) != NULL) {
				oprs[strlen(oprs)-1] = '\0';
				if(oprs[0] == 'i') {
						printTree(bst_head);
				}
				if(oprs[0] == 'n') {
						printTree(bst_sort);
				}
				if(oprs[0] == 's') {
						findTree(bst_head,getpart(&oprs[1]));
				}
				if(strcmp(oprs,"q") == 0) {
						break;
				}
				printf("usr ->");
		}
		return 0;
}
