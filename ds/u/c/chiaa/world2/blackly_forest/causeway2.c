//u/c/chiaa/world2/blackly_forest/causeway2.c

#include <ansi.h>    
inherit ROOM;

void create()
{
        set("short", "�ۤl��");
        set("long", @LONG
�A���b�@���ѸH�ۤl�Q�������W,�T������,�ܮe���^��,
�|�P�����u�۷���t,�F�褣���B,���z�X�G��!!
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
    "north"       : __DIR__"road7",      //�L���p��7
    "south"       : __DIR__"trail2",     //�ծ|2
    "northwest"   : __DIR__"road5",      //�����p��5
    "southwest"   : __DIR__"trail1",     //�ծ|1

]));
       
            setup();
replace_program(ROOM);
}

