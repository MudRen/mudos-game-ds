//u/c/chiaa/world2/little flower_island/champaign5.c

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
        set("exits", ([ /* sizeof() == 2 */
       "east"        : __DIR__"champaign4",    //����4
       "northwest"   : __DIR__"champaign1",    //����1
    ]));
       
            setup();
replace_program(ROOM);
}
