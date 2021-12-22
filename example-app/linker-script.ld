ENTRY(main)
SECTIONS
{
    . = 0x8CA00080;
    .text :
    {
        *(.text.main);
        *(.text*);
    }
}