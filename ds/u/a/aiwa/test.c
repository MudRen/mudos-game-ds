#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
        set ("short", HIG "darkfool" NOR);
        set ("long", @LONG
���դ�
LONG);
        set("valid_startroom", 1);
        set("exits", ([
        "morral":"/u/m/morral/workroom",
        ]));
        setup();
}
