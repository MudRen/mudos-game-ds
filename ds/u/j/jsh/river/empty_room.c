#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "半空中");
        set("long", @LONG
你正快速的掉落.......強大的離心力....讓你非常難受!
LONG
);
set("outdoors","land");
setup();
}
