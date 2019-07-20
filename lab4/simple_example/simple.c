#include <stdio.h>
#include <stdlib.h>

void write_to_file()
{
  FILE *f = fopen("./data/simple.txt", "w");
  char *hw;
  hw = "Hello World!\n";
  fprintf(f, "%s", hw);
  fclose(f);
}

void read_secret()
{
  char * buffer = 0;
  long length;
  FILE *f = fopen("./data/secret.txt", "r");
  if(f)
  {
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    buffer = malloc(length);
    if(buffer)
    {
      fread(buffer, 1, length, f);
    }
    fclose(f);
  }
  if(buffer)
  {
    printf("%s", buffer);
  }
}

int main()
{
  write_to_file();
  read_secret();
  return 0;
}
