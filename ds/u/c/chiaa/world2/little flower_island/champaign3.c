//u/c/chiaa/world2/little flower_island/champaign3.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIG"����"NOR);
        set("long",@LONG
�o�̬O�@��L�ڪ��j���,�}�}�������j�����p
�j�����i��,�@�}�@�}�V�Aŧ��,�٬O�n��!!
�A�Pı�M�D�L���j�صۧA������,�O�H���m����!!
�F�n�褣���B�n�����y�a�V!!


LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       "west"       : __DIR__"champaign4",    //����4
       "southeast"  : __DIR__"cliff1",        //�a�V1
       
    ]));
       
            setup();
replace_program(ROOM);
}
