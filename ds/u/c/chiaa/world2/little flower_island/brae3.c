//u/c/chiaa/world2/little flower_island/brae3.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", CYN"�s�Y"NOR);
        set("long",@LONG
�o�̬O�p��骺�s�Y,�Ө�o�̻P�˪L���Pı�O�������P��
���I�~���a�����H�樫��[����,�|�P���������A�O���Aı�o
���t����,���A����ı���P�F�f��,�]���C�F�٤�!!

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
      
        "east"   : __DIR__"brae2",         //�s�Y2
        "west"   : __DIR__"champaign1",    //����1
   ]));
       
            setup();
replace_program(ROOM);
}
