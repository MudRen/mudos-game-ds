//u/c/chiaa/world2/little flower_island/champaign6.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIG"����"NOR);
        set("long",@LONG
�o�̬O�@��L�ڪ��j���,�}�}�������j�����p
�j�����i��,�@�}�@�}�V�Aŧ��,�٬O�n��!!
�A�Pı�M�D�L���j�صۧA������,�O�H���m����!!
�n�褣���B�n�����Ӭ}��!!


LONG
        );
        set("exits", ([ /* sizeof() == 3 */
       "west"        : __DIR__"rock4",         //���۰�4
       "north"       : __DIR__"champaign2",    //����2
       "south"       : __DIR__"rock5",         //���۰�5
    ]));
       
            setup();
replace_program(ROOM);
}
