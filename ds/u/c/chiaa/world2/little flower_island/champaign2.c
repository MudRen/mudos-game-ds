//u/c/chiaa/world2/little flower_island/champaign2.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIG"����"NOR);
        set("long",@LONG
�o�̬O�@��L�ڪ��j���,�}�}�������j�����p
�j�����i��,�@�}�@�}�V�Aŧ��,�٬O�n��!!
�A�Pı�M�D�L���j�صۧA������
�O�H���m����!!


LONG
        );
        set("exits", ([ /* sizeof() == 3 */
       "south"      : __DIR__"champaign6",    //����6
       "east"       : __DIR__"champaign1",    //����1
       "northeast"  : __DIR__"brae1",         //�s�Y1
   
    ]));
       
            setup();
replace_program(ROOM);
}
