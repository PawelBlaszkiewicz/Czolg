#include"obrazek.h"

void read_png_file(char *filename, int *width, int *height, 
     png_byte *color_type,  
     png_byte *bit_depth, png_bytep **row_pointers) {

  FILE *fp = fopen(filename, "rb");

  png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if(!png) abort();

  png_infop info = png_create_info_struct(png);
  if(!info) abort();

  if(setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  png_read_info(png, info);
  
  *width      = png_get_image_width(png, info);
  *height     = png_get_image_height(png, info);
  *color_type = png_get_color_type(png, info);
  *bit_depth  = png_get_bit_depth(png, info);

  // Read any color_type into 8bit depth, RGBA format.
  // See http://www.libpng.org/pub/png/libpng-manual.txt

  if(*bit_depth == 16)
    png_set_strip_16(png);

  if(*color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb(png);

  // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
  if(*color_type == PNG_COLOR_TYPE_GRAY && *bit_depth < 8)
    png_set_expand_gray_1_2_4_to_8(png);

  if(png_get_valid(png, info, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha(png);

  // These color_type don't have an alpha channel then fill it with 0xff.
  if(*color_type == PNG_COLOR_TYPE_RGB ||
     *color_type == PNG_COLOR_TYPE_GRAY ||
     *color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_filler(png, 0xFF, PNG_FILLER_AFTER);

  if(*color_type == PNG_COLOR_TYPE_GRAY ||
     *color_type == PNG_COLOR_TYPE_GRAY_ALPHA)
    png_set_gray_to_rgb(png);

  png_read_update_info(png, info);

  if (*row_pointers) abort();

  *row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * *height);
  for(int y = 0; y < *height; y++) {
    (*row_pointers)[y] = (png_byte*)malloc(png_get_rowbytes(png,info));
  }

  png_read_image(png, *row_pointers);

  fclose(fp);

  png_destroy_read_struct(&png, &info, NULL);
}

void write_png_file(char *filename, int width, int height, 
     png_byte color_type,  
     png_byte bit_depth, png_bytep *row_pointers) {
  int y;

  FILE *fp = fopen(filename, "wb");
  if(!fp) abort();

  png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
  if (!png) abort();

  png_infop info = png_create_info_struct(png);
  if (!info) abort();

  if (setjmp(png_jmpbuf(png))) abort();

  png_init_io(png, fp);

  // Output is 8bit depth, RGBA format.
  png_set_IHDR(
    png,
    info,
    width, height,
    8,
    PNG_COLOR_TYPE_RGBA,
    PNG_INTERLACE_NONE,
    PNG_COMPRESSION_TYPE_DEFAULT,
    PNG_FILTER_TYPE_DEFAULT
  );
  png_write_info(png, info);

  // To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
  // Use png_set_filler().
  //png_set_filler(png, 0, PNG_FILLER_AFTER);

  if (!row_pointers) abort();

  png_write_image(png, row_pointers);
  png_write_end(png, NULL);

  for(int y = 0; y < height; y++) {
    free(row_pointers[y]);
  }
  free(row_pointers);

  fclose(fp);

  png_destroy_write_struct(&png, &info);
}

void process_png_file(int width, int height, png_bytep *row_pointers) {
  for(int y = 0; y < height; y++) {
    png_bytep row = row_pointers[y];
    for(int x = 0; x < width; x++) {
      png_bytep px = &(row[x * 4]);
      // Do something awesome for each pixel here...
      //printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
      // px - wskazuje na skladowa R pixela o wspolrzednych x,y!
      (*px) = (int) (*px) * 0.75;
      *(px+1) = (int) (*(px+1)) * 0.75;
      *(px+2) = (int) (*(px+2)) * 0.75;
    }
  }
}

png_bytep * create_image(int width, int height) {
  png_bytep *row_pointers = (png_bytep*)malloc(sizeof(png_bytep) * height);
  for(int y = 0; y < height; y++) {
    row_pointers[y] = (png_byte*)malloc(4*width);
  }

  return row_pointers;
}

void copy_tile(int xs, int ys, int width, int height, png_bytep *row_pointers, png_bytep *row_pointers_from, int idx) {
  for(int y = 0; y < height; y++) {
    png_bytep row = row_pointers[ys+y];
    png_bytep row_from = row_pointers_from[y];
    for(int x = 0; x < width; x++) {
      png_bytep px = &(row[(xs + x) * 4]);
      png_bytep px_from = &(row_from[(32*idx + x) * 4]);
      (*px) = *(px_from);
      *(px+1) = *(px_from+1);
      *(px+2) = *(px_from+2);
      *(px+3) = *(px_from+3);
    }
  }
}

void narysuj_mape_png(int a, int b, int mapa[a][b], char *arg1, char *arg2)
{
  int width, height;
    png_byte color_type;
    png_byte bit_depth;
    png_bytep *row_pointers = NULL;
    png_bytep *row_pointers_out = NULL;

  read_png_file( arg1 ,&width, &height, &color_type, &bit_depth, &row_pointers);
  row_pointers_out = create_image( 32*b , 32*a );

  for( int i=0 ; i<b ; i++)
    {
        for(int j=0 ; j<a ; j++)
        {
            if(mapa[j][i]==3)
            {
              copy_tile(32*i , 32*j , 32 , 32 ,  row_pointers_out, row_pointers, 0);
            }
            else if(mapa[j][i]==1)
            {
              copy_tile(32*i , 32*j , 32 , 32 ,  row_pointers_out, row_pointers, 2);
            }
            else if(mapa[j][i]==2)
            {
              copy_tile(32*i , 32*j , 32 , 32 ,  row_pointers_out, row_pointers, 1);
            }
        }
    }

    write_png_file( arg2 , 32*b , 32*a , color_type, bit_depth , row_pointers_out);
    write_png_file(arg1, width, height, color_type, bit_depth , row_pointers);
}