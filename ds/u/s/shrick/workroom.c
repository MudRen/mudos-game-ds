#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
        set ("short", HIW "�ѤU���a" NOR);
        set ("long", @LONG
�o�̬O�ѤU�a�ڭ̪����}��............�S����S�O������....
LONG);
set("valid_startroom", 1);
        set("exits", ([
        "west": __DIR__"bigdoor",
        "wiz":"/d/wiz/hall1",
        "down":"/u/s/shrick/rooms/center",
        ]));
        set("outdoors","bigdoor");
        setup();
}
#include <ansi.h>

void init()
{
write(HIG"�w����{�ѤU���a\n"NOR);
}

