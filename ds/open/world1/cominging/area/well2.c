#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "������");
        set("long",@LONG
�o�̬O�����U�A�b�o�̦��@�ǨǪ��ͪ��A���O�C��@�����A���b�V
�A�K�K�j�s�A���L�L��A�Ө��S������ˮ`�O�i���A�Ӧb�F��O�����A
�q���������y�y�L�ӡC
LONG
        );
        set("exits", ([
  "east" : __DIR__"well.c",
])); 
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

