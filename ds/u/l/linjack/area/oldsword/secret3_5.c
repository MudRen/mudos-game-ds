#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�A����o, ���u�L�L���{��, �Q�����t, �z�A�����@�����
�ө�, �j���٬O���򳣬ݤ��쪺�a.
LONG
    );
 set("exits",([ "north":__DIR__"secret3_4",
                "east":__DIR__"secret3_6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
