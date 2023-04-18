# 0 "main.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "main.c"





int main()
{

  (*((int*)0x40021018)) |= 1U << 4;



  (*((int*)((0x40011000U) + 0x4))) |= (0x3 << 20);

  (*((int*)((0x40011000U) + 0x4))) &= ~(0x3 << 22);

  while(1){

    (*((int*)((0x40011000U) + 0xC))) |= 1<<13;


    for(int i = 0; i < 500000; i++);


    (*((int*)((0x40011000U) + 0xC))) &= ~(1U<<13);


    for(int i = 0; i < 500000; i++);

  }

  return 0;
}
