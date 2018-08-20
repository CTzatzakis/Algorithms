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

//Merge Sort
/*
 It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. 
 The merge() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes 
 that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. 
 
 Merges two subarrays of arr[].
 First subarray is arr[l..m]
 Second subarray is arr[m+1..r]
*/

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
/========================================================/
