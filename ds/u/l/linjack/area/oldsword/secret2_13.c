#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o�̦A���F�n¶�h�i�H�ݨ�@�I���u, �i��O����X�f,
�A�i�H�L�h�ݬ�......
LONG
    );
 set("exits",([ "southeast":__DIR__"secret2_14",
                "north":__DIR__"secret2_12",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
