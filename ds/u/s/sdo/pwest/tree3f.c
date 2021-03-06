inherit ROOM;

void create()
{
	set("short", "神木的最頂端");
	set("long", @LONG
你現在正站在神木的最頂端，這裡充滿著那股力量。你抬頭想上
看，發現有一顆巨大的水晶懸浮在半空中，看來那就是這股力量的源
頭了。
LONG
	);
	set("item_desc",([
        "水晶":	"一顆巨大、神秘的水晶。好像憑藉著自己的力\n"
        	"量漂浮在空中不停的旋轉著，並且不停的向四\n"
        	"周散放著它的力量。\n",
       	]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"tree2f",
	]));
	set("objects",([
	__DIR__"npc/treeking.c":1,
	]));

	setup();
	replace_program(ROOM);
}
