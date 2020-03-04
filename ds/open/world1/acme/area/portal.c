// Room: /u/a/acme/area/portal.c

inherit ROOM;

void create()
{
	set("short", "神武大門");
     set("light",1);
	set("long", @LONG
這裡是神武教的大門，大門上有三個火紅大字，上面寫著【神武教】
，大門是用精鋼所建造而成，就算是用火炮也是打不破的，實是令人贊嘆
建造此鋼門的工匠之鬼斧神工啊！
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"hills3",
  "south" : __DIR__"corridor",
]));
    set("objects",([
       __DIR__"npc/guard1" : 4,
    ]) );
	set("no_clean_up", 0);

	setup();
}
