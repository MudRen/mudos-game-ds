//u/c/chiaa/world2/little flower_island/forest2.c

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
       "north"      : __DIR__"sand3",     //�F�y3
       "west"       : __DIR__"forest3",   //�˪L3
       "southeast"  : __DIR__"forest4",   //�˪L4
  ]));
       
            setup();
replace_program(ROOM);
}
