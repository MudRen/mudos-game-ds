#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
        set ("short", HIG "�p�A�u�]" NOR);
        set ("long", @LONG
�p�A�u�]......�c�@�@���k������....�D�`�}�G
LONG);
        set("valid_startroom", 1);
        set("exits", ([
	"down":"/open/world2/meetroom",
"up":__DIR__"classroom",
        ]));
        setup();
        call_other("/u/e/eeman/eeman_b","???");
}

void init()
{
write("hi\n");
}
