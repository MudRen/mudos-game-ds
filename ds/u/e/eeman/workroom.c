#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
        set ("short", HIG "小澤真珠" NOR);
        set ("long", @LONG
小澤真珠......惡作劇之吻的角色....非常漂亮
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
