//u/c/chiaa/world2/little flower_island/champaign1.c

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
       "west"         : __DIR__"champaign2",    //����2
       "east"         : __DIR__"brae3",         //�s�Y3
       "southeast"    : __DIR__"champaign5",    //����5
      ]));
       
            setup();
replace_program(ROOM);
}
