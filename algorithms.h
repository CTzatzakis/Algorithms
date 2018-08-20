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