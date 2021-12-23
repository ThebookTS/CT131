//BookTs
#include <stdio.h>
 
int TinhGiaiThua( int n )
{
    if( 0 == n )   
        return 1;
    return n*TinhGiaiThua( n-1 );
}
 
int TinhToHop( int k, int n )
{
    return TinhGiaiThua( n )/(TinhGiaiThua( k )*TinhGiaiThua( n - k ));
}
 
void VeTgPascal( int h )
{
    int i, j;
   
    for( i = 0; i < h; i++ )
    {
        for( j = 0; j <= i; j++ )
            printf( "%4d", TinhToHop( j, i ) );
        printf( "\n" );
    }
}
 
int main()
{
    int h;
 
    do
    {
        printf( "Nhap do cao tam giac Pascal: " );
        scanf( "%d", &h );
    }
    while( h <= 0 );
   
    printf( "Tam giac Pascal co do cao %d:\n", h );
    VeTgPascal( h );
   
    return 0;
}
