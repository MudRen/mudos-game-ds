// pray_building1.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"神殿─" HIW"前廳"NOR);
        set("long",@LONG
  這裡是猶羅村的神殿，為那些將要出海的海賊們禱告
乞求保祐的地方。這裡是前廳。四周乾乾淨淨的好似常
常有人來打掃的樣子。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"pray_bridge",
                "west"    : __DIR__"pray_bd2",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
