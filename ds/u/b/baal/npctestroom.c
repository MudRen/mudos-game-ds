#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",MAG"������"NOR);

 set("long",@LONG
�o�̬O���䪺������, �U�W��q, ���ܦh�������a��, �����O�����
�]�k�U������, �|�B��񴳴�, �@�Ѹ{����j���b����...

LONG
    );
 set("exits",([ "up" : __DIR__"workroom2",
    ]));
        set("objects", ([ 
          __DIR__"area/dst/npc/poorguard" : 1,
          __DIR__"area/dst/npc/skeguard1" : 5,
          __DIR__"weapon/helldog" : 5,
        ]));

        set("light",1);
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
 

}
