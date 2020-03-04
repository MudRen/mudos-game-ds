// Room: /u/a/acme/area/howe.c
inherit ROOM;
void create()
{
	set("short", "洞穴");
	set("long", @LONG
這裡全是沙子，你的口鼻之中卻也塞滿了細沙，你感覺到呼吸困難，
頭昏眼花，四周黑漆漆的，不禁令人產生畏懼，你舉起雙手在這洞穴摸索
，在你絕望之時，你的雙手突然摸到了一面牆，在這個洞穴中竟有一道牆
，令人起了好奇之心。
LONG
	);
set("exits", ([ /* sizeof() == 1 */
    "up" : __DIR__"hills1.c",
]));
set("objects" , ([
     __DIR__"npc/worm.c" : 4,
]) );
	set("no_clean_up", 0);
    set("item_desc", ([
        "牆" : "這道牆又厚又硬，看來是敲打不開的，說不定你能用推(push)的。\n",
    ]));
	setup();
}
void init()
{
        add_action("typepush","push");
}
     int typepush(string arg)
{
       object me;
        me=this_player();
        if(arg != "牆") return 0;
         else {
        message_vision(
        "$N使勁的推著牆，牆應聲而開。\n\n"
         ,me);
         set("exits", ([
          "up" : __DIR__"hills1",
          "south" : __DIR__"howe1",
]));
 return 1;
        }
}

