//u/c/chiaa/world2/little flower_island/forest1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", GRN"�˪L"NOR);
        set("long",@LONG
�o�̬O�p��骺�@�y�˪L,�|�P�L����¶,�ɾB���u,
��o���t�ܷ����H�P��}�}������,�˪L�̶ǥX�U�س��~���s�n,
��O�H�򰩮��M!���A�椧�o�B!


LONG
        );
        set("exits", ([ /* sizeof() == 3 */
       "north"      : __DIR__"sand1",     //�F�y1
       "east"       : __DIR__"sand5",     //�F�y5
       "southeast"  : __DIR__"sand6",     //�F�y6
  ]));
       
            setup();
replace_program(ROOM);
}
