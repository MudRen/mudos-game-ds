// pray_building2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIY"神殿─" HIW"後廳"NOR);
        set("long",@LONG
  這裡是猶羅村的神殿，為那些將要出海的海賊們禱告
乞求保祐的地方，這裡是後廳。環顧四周座落著數不清
的神像。
LONG
        );
        set("exits", ([/*sizeof=2*/
                "east"    : __DIR__"pray_bd1",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}


