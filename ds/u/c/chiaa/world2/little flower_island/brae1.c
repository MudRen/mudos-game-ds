//u/c/chiaa/world2/little flower_island/brae1.c

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
        set("exits", ([ /* sizeof() == 1 */
      
        "southwest"   : __DIR__"champaign2",    //�쳥2
  ]));
       
            setup();
replace_program(ROOM);
}
