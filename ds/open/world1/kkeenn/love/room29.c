#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"情城池左偏堂"NOR);
        set("long", @LONG
這裡是情城池的左偏堂，這裡如同正堂，擺設許多奇花異木，散發出
陣陣迷人的清香，大殿內前有一黃金爐，黃金爐內飄來陣陣麝檀香，整個
偏堂香煙裊裊的，如夢如幻。
LONG
        );
        set("exits", ([ 
  "east"  : __DIR__"room27",
  ]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/left" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}
