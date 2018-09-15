#include "Utilitarios.h"
int thisone;
int main()
{
    int dpi = 72;
    int width = 400;
    int height = 400;
    int n = width * height;
    ColorRGB* pixeles = new ColorRGB[n];
    for(int x= 0; x < width; x++)
    {
		for( int y = 0; y < height; y++)
		{
			thisone = y*width+x;
           
            pixeles[thisone].r = 1.0;
			pixeles[thisone].g = 1.0;
			pixeles[thisone].b = 0;
            			
		}
        
    }
     for(int x= 100; x < width-100; x++)
    {
		for( int y = 100; y < height-100; y++)
		{
			thisone = y*width+x;
           
            pixeles[thisone].r = 1.0;
			pixeles[thisone].g = 0;
			pixeles[thisone].b = 0;
            			
		}
        
    }
    savebmp("img.bmp", width, height, dpi, pixeles);
    return 0;
}