#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"情城池九言陣["HIW"前"HIC"]"NOR);
        set("long", @LONG
你正站在情城池的九言陣密陣，只見得四週盡是濃霧彌漫，伸手不見
五指，在陣陣濃霧的正中央，有著一張太師椅上面坐著一位童顏鶴髮的絕
世美女，濃霧在她的手旁凝聚成一條狀物，看來那位女子的功力與其他前
面八位有很大的不同處。
LONG
        );
        set("exits", ([ /*中心點[臨]file_name room18*/
  "out"  : __DIR__"room25",
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/ron" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);

}


