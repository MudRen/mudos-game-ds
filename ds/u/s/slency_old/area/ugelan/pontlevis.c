// Room: /u/s/slency/area/ugelan/pontlevis.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"吊橋"NOR);
	set("long", @LONG
這裡是橫越皇宮護城河的一座大形吊橋，河水映照著金黃色的日光
，將吊橋照得閃閃發光，你的前方有許多侍衛駐守在宮門前，光看如此
的氣勢，你又不禁對這幽遮蘭帝國敬畏了幾分。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"royalty",
  "south" : __DIR__"road5",
]));
	set("item_desc", (["吊橋" : "一座雄偉的吊橋，你隱約看到吊橋下有一處土丘可以站立。\n" 
	]));
	set("no_clean_up", 0);
	set("outdoors", "land");
	setup();
}	
void init()
{
	add_action("do_jump", "jump");
}
int do_jump(string arg)
{
	if(arg != "吊橋") return 0;
	this_player()->move(__DIR__"underpontlevis");
	return 1;
}
