#include <room.h>
inherit ROOM;
void create()
{
 set("short","��L�����p�D");
 set("long",@LONG
�A�����b��L�����p�D�����W, �@���W�èS������S�O
���ƪ��ާA�`�N, �A�`�O��߫��b���V���󤧸����W��.
LONG
    );
 set("exits",([ "south":__DIR__"mountroad3_3",
                "northeast":__DIR__"mountroad3_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}