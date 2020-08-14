void preprocessingKMP(){
    int i=0, j=-1;
    nxt[i]=j;
    while (i<m)
    {
        while (j>=0 && t[i]!=t[j]) j= nxt[j];
        i++; j++;
        nxt[i]=j;
    }
}
void kmpSearch()
{
    int i=0, j=0;
    while (i<n)
    {
        while (j>=0 && s[i]!=t[j]) j = nxt[j];
        i++; j++;
        if (j==m)
        {
            report(i-j);
            j= nxt[j];
        }
    }
}
