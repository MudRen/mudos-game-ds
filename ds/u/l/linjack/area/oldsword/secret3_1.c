#include <room.h>
inherit ROOM;
void create()
{
 set("short","���Y���Y");
 set("long",@LONG
�A�Ө�F���Y�����Y, �A���F�_��V���q�D��, ���G����
�L�����i�H�e�i.....
LONG
    );
 set("exits",([ "west":__DIR__"secret1_9",
                "northeast":__DIR__"secret3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
