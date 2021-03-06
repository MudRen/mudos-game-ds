// Room: /u/s/sub/area/village/tree2.c

inherit MOBROOM;

void create()
{
	set("short", "樹上");
	set("long", @LONG
透過扶疏的枝葉可以看見這裡蔚藍的天空，絲毫沒有任何被污染的痕
跡。樹上不時有些小動物跑來跑去，讓人也沾染了這裡無憂無慮的氣氛，
不禁起了退隱之心。由於這裡距離地面有四十幾公尺的高度，一眼望去整
個山谷都一目了然。北邊有條粗壯的樹枝延伸到不遠處的峭壁上。
LONG
	);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"tree1",
  "north" : __DIR__"tree3",
]));
    set("chance",50);
    set("mob_amount",2);
	set("world", "undefine");
        set("mob_object",({     
        __DIR__"npc/village_worm_1",
        }) );
	set("no_clean_up", 0);

	setup();
}
