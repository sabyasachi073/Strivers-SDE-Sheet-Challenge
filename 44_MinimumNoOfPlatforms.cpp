int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);

    int platforms=1, res=1;
    int i=1, j=0;
    while(i<n && j<n) {
        if(at[i]<=dt[j])
        {
            platforms++;
            i++;
        }
        else{
            platforms--;
            j++;
        }

        if(platforms>res)
            res = platforms;
    }
    return res;
}
