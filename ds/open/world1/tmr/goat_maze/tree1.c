// Room: /open/world1/tmr/goat_maze/tree1.c

inherit ROOM;

void create()
{
	set("short", "贛林樹洞");
	set("long", @LONG
你正爬在贛林老木的樹洞中，腳旁盡是腐臭的爛泥巴，還有幾十隻的
不知名毛蟲跟甲蟲，正在泥巴中鑽來鑽去，甚至還有幾隻爬到你的臉上跟
背上，搞的你心裡發毛。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"maze10",
  "north" : __DIR__"tree2",
]));
        set("objects", ([
                __DIR__"npc/bug" : 1 + random(3), 
        ]) );

	set("current_light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
