#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#define MAXLEN 200

struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right
};

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;
	if (p == NULL) {
		p = (struct tnode *)malloc(sizeof(struct tnode));
		p->word = malloc((strlen(w) + 1) * sizeof(char));
		strcpy(p->word, w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	} else if ((cond = strcmp(w, p->word)) == 0) {
		p->count++;
	} else if (cond < 0) {
		p->left = addtree(p->left, w);
	} else {
		p->right = addtree(p->right, w);
	}
	return p;
}

void printtree(struct tnode *p)
{

	if (p != NULL) {
		printtree(p->left);
		printf("%s %d\n", p->word, p->count);
		printtree(p->right);
	}
}

main()
{
	struct tnode *tree;
	tree = NULL;
	char *temp[MAXLEN];
	int len;
	while (len = getword(temp)) {
		tree = addtree(tree, temp);
	}
	printtree(tree);
}
