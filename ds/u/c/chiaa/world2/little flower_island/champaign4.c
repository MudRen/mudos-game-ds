//u/c/chiaa/world2/little flower_island/champaign4.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIG"����"NOR);
        set("long",@LONG
�o�̬O�@��L�ڪ��j���,�}�}�������j�����p
�j�����i��,�@�}�@�}�V�Aŧ��,�٬O�n��!!
�A�Pı�M�D�L���j�صۧA������,�O�H���m����!!

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
       "east"        : __DIR__"champaign3",    //����3
       "west"        : __DIR__"champaign5",    //����5
       "enter"       : __DIR__"cave2",         //�}��2
       "northeast"   : __DIR__"forest6",       //�˪L6
    ]));
       
            setup();
replace_program(ROOM);
}
