//Reverse Polish Notation - RPN
void push(int stack[],int *t,int obj) 
{    
	if ((*t) == N-1)       
	{
		printf("Stack overflow...\n");
		getch();
		abort();
	}
    else
		stack[++(*t)] = obj; 
} 

int pop(int stack[],int *t) 
{
	int r; 
	if ((*t) < 0)       
	{
		printf("Stack empty...\n");
		printf("Error in expression.\n");
		getch();
		abort();
	}
    else
        r = stack[(*t)--]; 
 
   return r; 
   } 
//
PTR push(char obj, PTR t) 
{    
	PTR newnode; 
	newnode = malloc(sizeof(struct node));
	newnode->data = obj;
	newnode->next = t;
	t = newnode;
	return t;
} 
 
PTR pop(PTR  t, char *obj) 
{    
	PTR p;
	if (t == NULL)       
	{          
		printf("Stack empty.\n");          
		getch();        
	}
	else
	{
		p = t;
		t = t->next;
		*obj = p->data;
		free(p);
	}    
	return t; 
}
//binary search
int binarysearch(int left, int right, Person p[], int x) 
{
    int mid, pos; 
 
	if (left > right)
		pos = -1;
	else
		{
			mid = (left + right) / 2;        
			if (p[mid].am == x)            
				pos = mid;        
			else          
				if (x < p[mid].am)
					pos = binarysearch(left,mid-1,p,x);          
				else             
					pos = binarysearch(mid+1,right,p,x);       
		}    
		
	return pos; 
} 
//insert node
void insert_node(PTR *pt,int x)
{
  PTR t;
  t=*pt;
  if(t==NULL)
   {
     t=malloc(sizeof (struct treenode));
     t->data=x;
     t->left=NULL;
     t->right=NULL;
   }
   else
   if (x<t->data)
      insert_node(&(t->left),x);
     else
      insert_node(&(t->right),x);
   *pt=t;
};
// find node
void find_node(PTR t,int n,int i)
{
  i++;
  if(t==NULL)
    {
      printf("Not Found\n");
      printf("Repeats: %i",i);
    }
  else if(n==t->data)
    {
      printf("Found\n");
      printf("Repeats: %i",i);
    }
  else if(n<t->data)
      find_node(t->left,n,i);
  else
      find_node(t->right,n,i);
}
// ptr create list 
Ptr createList(Ptr p,int a[],char b[][10],int c[])
{
 int i;
 Ptr current;
 for(i=0;i<N;i++)
  {
   current=malloc(sizeof(struct node));
   current->data.cid=a[i];
   strcpy(current->data.cartype,b[i]);
   current->data.km=c[i];
   current->next=p;
   p=current;
  }
  return p;
} 
// enqueue
void enqueue(int n,PTR *pf,PTR *pr)
{
  PTR newnode;
  newnode = malloc(sizeof(struct node));
  newnode->data=n;
  newnode->next=NULL;
if ((*pf)==NULL)
  {
	*pf=newnode;
	*pr=newnode;
  }
else
  {
    (*pr)->next=newnode;
    *pr=newnode;
  }
}
//dequeue
void dequeue(PTR *pf, PTR *pr)
{
  PTR p;
if ((*pf)==NULL)
     printf("\nQueue empty. No elements to delete.\n");
else
  {
      p=*pf;
     *pf=(*pf)->next;
  if ((*pf)==NULL)
     *pr=*pf;
      printf("\n%d has been deleted...\n",p->data);
      free(p);
  }
getch();
}

void preorder_traversal(PTR t)
{
  if (t!=NULL)
   {
     printf("%i ",t->data);
     preorder_traversal(t->left);
     preorder_traversal(t->right);
   }
}

void inorder_traversal(PTR t)
{
  if (t!=NULL)
   {
    inorder_traversal(t->left);
    printf("%i ",t->data);
    inorder_traversal(t->right);
   }
}

void postorder_traversal(PTR t)
{
  if (t!=NULL)
    {
      postorder_traversal(t->left);
      postorder_traversal(t->right);
      printf("%i ",t->data);
    }
}
// bubblie sort
void bubbleSort(int arr[], int n) 
{
      bool swapped = true;
      int j = 0;
      int tmp;
      while (swapped) 
      {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) 
	    {
		    if (arr[i] > arr[i + 1]) 
		    {
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			swapped = true;
                  }
            }
      }
}
//Selection Sort
/*
Selection sort is an O(n2) sorting algorithm, simple in its programming and it can over perform other sorts in certain situations.
*/
void selectionSort(int arr[], int n) 
{
	int i, j, minIndex, tmp;    
	
	for (i = 0; i < n - 1; i++) 
	{
		minIndex = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

            if (minIndex != i) 
			{
                tmp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = tmp;
            }
	}
}
// Insertion Sort
/*
Insertion sort is an O(n2) sorting algorithms. A sorting algorithm with quadratic complexity, 
it is applied in practice for sorting small arrays of data and to improve quicksort routine.
*/
void insertionSort(int arr[], int length) 
{
	int i, j, tmp;
	
	for (i = 1; i < length; i++) 
	{
		j = i;
		while (j > 0 && arr[j - 1] > arr[j]) 
		{
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;

		}
	}
}
// Quick Sort
/*
Quicksort is a fast sorting algorithm, it has O(n log n) complexity, suitable for sorting big data volumes. 
*/
void quickSort(int arr[], int left, int right) 
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
      /* partition */
	while (i <= j) 
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
        if (i <= j) 
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}

	};
      /* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}
