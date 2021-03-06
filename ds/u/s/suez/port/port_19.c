#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","薩爾薩斯廣場");
	set("long",@LONG
這裡已經超過了原本薩爾薩斯的範圍，是完全新開發的區域。相對於
舊港區，這裡經過相當的規劃及建設，從這裡往南是主要的商業區，往西
是商務碼頭，往東則是相當壯觀的尤拉大道。新穎的地下水道的開口也在
此，商人們稱這些新開發的區域為「就連矮人也會嘆息的設計」。不過這
些區域的人幾乎都是外來者，原本薩爾薩斯的居民反而不喜歡這裡。
LONG 
);
	set("exits",([
	    "north":__DIR__"port_11",
	    "east":__DIR__"port_20",
            "west":__DIR__"port_15",
	    "south":__DIR__"port_23",
		]));
	set("objects",([
	    __DIR__"npc/ad_wm":2,
	    __DIR__"npc/ad_mn":3,
		]));
	set("item_desc",([
	    "地下水道":"這裡有個入口，可以通往薩爾薩斯的地下水道。(使用指令enter)\n"
	]));
	set("world","world1");
	set("outdoor","land");

	setup();

}
void init()
{
	add_action("do_enter","enter");
}
void do_enter()
{
	this_player()->move(__DIR__"port_b1");
	return;	
}