#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COUNT 10
#define MAX_HEIGHT 1000
#define INFINITY (1<<20)

/* ----------NODE---------- */

typedef struct Tree Tree;
struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
};

struct Tree *ROOT = NULL;
void insert(int x);
struct Tree* recursive_insert(struct Tree *ptr, int x);
int search(struct Tree *ptr, int x);
void print2DUtil(struct Tree *root, int space);
void print2D(struct Tree *root);

/* ----------PRINTING THE TREE---------- */

typedef struct asciinode_struct asciinode;
struct asciinode_struct {
  asciinode * left, * right;
  int edge_length; 
  int height;      
  int lablen;
  int parent_dir;   
  char label[11];  
};

int lprofile[MAX_HEIGHT];
int rprofile[MAX_HEIGHT];

int gap = 3;  
int print_next;    

int MIN (int X, int Y) {
    return ((X) < (Y)) ? (X) : (Y);
}

int MAX (int X, int Y) {
    return ((X) > (Y)) ? (X) : (Y);
}

asciinode * build_ascii_tree_recursive(Tree * t) {
    asciinode * node;
    if (t == NULL) return NULL;
    node = malloc(sizeof(asciinode));
    node->left = build_ascii_tree_recursive(t->left);
    node->right = build_ascii_tree_recursive(t->right);
    if (node->left != NULL) node->left->parent_dir = -1;
    if (node->right != NULL) node->right->parent_dir = 1;
    sprintf(node->label, "%d", t->data);
    node->lablen = strlen(node->label);
    return node;
}

asciinode * build_ascii_tree(Tree * t) {
    asciinode *node;
    if (t == NULL) return NULL;
    node = build_ascii_tree_recursive(t);
    node->parent_dir = 0;
    return node;
}

void free_ascii_tree(asciinode *node) {
    if (node == NULL) return;
    free_ascii_tree(node->left);
    free_ascii_tree(node->right);
    free(node);
}

void compute_lprofile(asciinode *node, int x, int y) {
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    lprofile[y] = MIN(lprofile[y], x-((node->lablen-isleft)/2));
    if (node->left != NULL) {
        for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) {
            lprofile[y+i] = MIN(lprofile[y+i], x-i);
        }
    }
    compute_lprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
    compute_lprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_rprofile(asciinode *node, int x, int y) {
    int i, notleft;
    if (node == NULL) return;
    notleft = (node->parent_dir != -1);
    rprofile[y] = MAX(rprofile[y], x+((node->lablen-notleft)/2));
    if (node->right != NULL) 
    {
      for (i=1; i <= node->edge_length && y+i < MAX_HEIGHT; i++) 
    {
        rprofile[y+i] = MAX(rprofile[y+i], x+i);
    }
    }
    compute_rprofile(node->left, x-node->edge_length-1, y+node->edge_length+1);
    compute_rprofile(node->right, x+node->edge_length+1, y+node->edge_length+1);
}

void compute_edge_lengths(asciinode *node) {
    int h, hmin, i, delta;
    if (node == NULL) return;
    compute_edge_lengths(node->left);
    compute_edge_lengths(node->right);
    if (node->right == NULL && node->left == NULL) node->edge_length = 0; 
    else {
        if (node->left != NULL) {
            for (i=0; i<node->left->height && i < MAX_HEIGHT; i++) {
    	        rprofile[i] = -INFINITY;
            }
            compute_rprofile(node->left, 0, 0);
            hmin = node->left->height;
        } else {
            hmin = 0;
        }
        if (node->right != NULL) {
            for (i=0; i<node->right->height && i < MAX_HEIGHT; i++) {
    	        lprofile[i] = INFINITY;
            }
            compute_lprofile(node->right, 0, 0);
            hmin = MIN(node->right->height, hmin);
        } else {
            hmin = 0;
        }
        delta = 4;
        for(i=0; i<hmin; i++) {
            delta = MAX(delta, gap + 1 + rprofile[i] - lprofile[i]);
        }
        if (((node->left != NULL && node->left->height == 1) || (node->right != NULL && node->right->height == 1))&&delta>4) {
            delta--;
        }
        node->edge_length = ((delta+1)/2) - 1;
    }
    h = 1;
    if (node->left != NULL) {
      h = MAX(node->left->height + node->edge_length + 1, h);
    }
    if (node->right != NULL) {
      h = MAX(node->right->height + node->edge_length + 1, h);
    }
    node->height = h;
}

void print_level(asciinode *node, int x, int level) {
    int i, isleft;
    if (node == NULL) return;
    isleft = (node->parent_dir == -1);
    if (level == 0) {
        for (i=0; i<(x-print_next-((node->lablen-isleft)/2)); i++) {
            printf(" ");
        }
        print_next += i;
        printf("%s", node->label);
        print_next += node->lablen;
    } else if (node->edge_length >= level) {
        if (node->left != NULL) {
            for (i=0; i<(x-print_next-(level)); i++) {
    	        printf(" ");
            }
            print_next += i;
            printf("/");
            print_next++;
        }
        if (node->right != NULL) {
            for (i=0; i<(x-print_next+(level)); i++) {
    	        printf(" ");
            }
            print_next += i;
            printf("\\");
            print_next++;
        }
    } else {
        print_level(node->left, x-node->edge_length-1, level-node->edge_length-1);
        print_level(node->right, x+node->edge_length+1, level-node->edge_length-1);
    }
}

void print_ascii_tree(Tree * t) {
    asciinode *proot;
    int xmin, i;
    if (t == NULL) return;
    proot = build_ascii_tree(t);
    compute_edge_lengths(proot);
    for (i=0; i<proot->height && i < MAX_HEIGHT; i++) {
        lprofile[i] = INFINITY;
    }
    compute_lprofile(proot, 0, 0);
    xmin = 0;
    for (i = 0; i < proot->height && i < MAX_HEIGHT; i++) {
        xmin = MIN(xmin, lprofile[i]);
    }
    for (i = 0; i < proot->height; i++) {
        print_next = 0;
        print_level(proot, -xmin, i);
        printf("\n");
    }
    if (proot->height >= MAX_HEIGHT) {
        printf("(This tree is taller than %d, and may be drawn incorrectly.)\n", MAX_HEIGHT);
    }
    free_ascii_tree(proot); 
}

/* ----------MAIN---------- */

int main() {
    insert(5);
    insert(2);
    insert(7);
    insert(6);
    insert(3);
    recursive_insert(ROOT, 10);
    recursive_insert(ROOT, -1);
    recursive_insert(ROOT, 8);
    insert(9);
    insert(1);
    print_ascii_tree(ROOT);
}

/* ----------ITERATIVE INSERTION---------- */

void insert(int x) {
    struct Tree *temp = (struct Tree*)malloc(sizeof(struct Tree));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    if(ROOT==NULL) {
        ROOT = temp;
        return;
    }
    struct Tree *current = ROOT;
    struct Tree *prev = NULL;
    while(current!=NULL) {
        prev = current;
        if(temp->data <= current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    if(x <= prev->data) prev->left = temp;
    else prev->right = temp;
    return;
}

/* ----------RECURSIVE INSERTION---------- */

struct Tree* recursive_insert(struct Tree *ptr, int x) {
    if(ptr==NULL) {
        struct Tree *temp = (struct Tree*)malloc(sizeof(struct Tree));
        temp->data = x;
        temp->left = NULL;
        temp->right = NULL;
        ptr = temp;
    } else if(x <= ptr->data) {
        ptr->left = recursive_insert(ptr->left, x);
    } else {
        ptr->right = recursive_insert(ptr->right, x);
    }
    return ptr;
}

/* ----------SEARCHING---------- */

int search(struct Tree *ptr, int x) {
    if(ptr==NULL) return 0;
    else if(ptr->data==x) return 1;
    else if(x<ptr->data) return search(ptr->left, x);
    else return search(ptr->right, x);
}

void print2DUtil(struct Tree *root, int space) { 
    // Base case 
    if (root == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print2DUtil(root->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf(" "); 
    printf("%d\n", root->data); 
  
    // Process left child 
    print2DUtil(root->left, space); 
} 

void print2D(struct Tree *root) { 
   // Pass initial space count as 0 
   print2DUtil(root, 0); 
} 
