//u/c/chiaa/world2/little flower_island/forest6.c

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
        set("exits", ([ /* sizeof() == 2 */
       "east"        : __DIR__"forest5",      //�˪L5
       "southwest"   : __DIR__"champaign4",   //����4
   
  
  ]));
       
            setup();
replace_program(ROOM);
}
