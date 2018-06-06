typedef struct
{
    int a;
    int b;
}dato;

int main()
{
    int v[5] = {1,2,4,5,6};

    int i;

    for(i=0; i<5; i++)
    {
        printf("%d\n", *(v+i));

    }

    return 0;
}
