//u/c/chiaa/world2/little flower_island/forest4.c

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
       "east"        : __DIR__"sand7",     //�F�y7
       "south"       : __DIR__"brae2",     //�s�Y2
       "northwest"   : __DIR__"forest2",   //�˪L2
  
  ]));
       
            setup();
replace_program(ROOM);
}
