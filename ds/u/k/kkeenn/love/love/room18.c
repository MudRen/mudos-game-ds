#include <ansi.h>;
inherit __DIR__"room";
void create()
{
        set("short", HIC"情城池九言陣["HIW"臨"HIC"]"NOR);
        set("long", @LONG
你正走在情城池的九言陣，只見得四週盡是濃霧彌漫，伸手不見五指
，在陣陣濃霧的正中央，站著一位白髮紅顏的絕世美女，濃霧在她的身旁
圍繞著就是近不了她的身旁五尺，看來那位女子也有相當的功力.....
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"room9", 
  "northeast"  : __DIR__"room19",
  "northwest"  : __DIR__"room20",
  "up"  : __DIR__"room21",
  "down"  : __DIR__"room22",
  "east"  : __DIR__"room23",
  "west"  : __DIR__"room24",
  "north"  : __DIR__"room25",
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/jan" : 1,
]));
        set("light",1);
        setup();
}

