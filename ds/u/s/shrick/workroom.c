#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
        set ("short", HIW "天下之家" NOR);
        set ("long", @LONG
這裡是天下家族們的歇腳站............沒什麼特別的環境....
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
write(HIG"歡迎光臨天下之家\n"NOR);
}

