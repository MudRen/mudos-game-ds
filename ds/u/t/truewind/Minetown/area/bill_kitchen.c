// Room: /u/t/truewind/Minetown/area/bill_kitchen.c

inherit ROOM;

void create()
{
	set("short", "酒吧的廚房");
	set("long", @LONG
廚房裡擺著冷藏櫃，調理桌，垃圾分解器等等東西，你發現天花
板上吊著一隻割斷脖子的六腳獸，鮮血直流，不遠處的地板上還用隔
菌布蓋著看起來是動物屍體的東西。這裡的空調系統似乎是壞了，冷
的你口裡直冒白霧，真搞不懂怎麼有人能忍受在這裡做菜??
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ 
        __DIR__"npc/chef" :1 ,
]));
	set("current_light", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"minetown_bill",
]));

	setup();
}
