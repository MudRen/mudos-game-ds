//u/c/chiaa/world2/little flower_island/cave1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", BLU"�}��"NOR);
        set("long",@LONG
�o�̪��Ů�Pı�۷�M�D,���A�P��@�}���P,�Q�𮧤@�U,
�A�o�{�a�W���@�Ǫ������u��,���G���H�b�o�̩~��L,
���L�b�o�t�q,���|���H�ϩO?�A���T���P��@�}�ôb,
�|�P��n�����@�ѥO�H�������Pı�C

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "out"   : __DIR__"rock3",         //���۰�3
  
   ]));
       
            setup();
replace_program(ROOM);
}
