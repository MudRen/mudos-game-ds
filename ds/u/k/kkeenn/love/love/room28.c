#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"情城池右偏堂"NOR);
        set("long", @LONG
這裡是情城池的右偏堂，這裡如同正堂，擺設許多奇花異木，散發出
陣陣迷人的清香，大殿內前有一銀炫爐，銀炫爐內飄來陣陣荷花香，整個
偏堂香煙裊裊的，如夢如幻。
LONG
        );
        set("exits", ([ 
  "west"  : __DIR__"room27",
  ]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/right" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}
