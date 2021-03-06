/**
 * Shadow's area [荒廢漁村 - a7]
 */
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW"碎石道"NOR);
	set("long",
"你走上一條鋪滿了碎石的小徑，黃土碎石夾雜其中，路面滿是坑\n"
"洞，飛揚的塵土讓你幾乎睜不開眼睛來仔細觀察四周的環境。小路兩\n"
"旁同樣是雜草叢生，偶有蚱蜢飛躍其間。乍看之下似乎是條沒有人煙\n"
"的羊腸小徑，西邊隱約有條被淹沒的"HIW"古道"NOR"，再朝北望去，在遙遠的彼\n"
"端彷彿有間小小的茅屋坐落在盡頭，向前碰碰運氣也許\會遇見人呢！\n"
	);
	set("outdoors","land");
	set("light",1);
	set("exits",([
		"north": __DIR__"a8",
		"south": __DIR__"a3",
	]));
  
  set("item_desc",(["古道": "一條埋沒在雜草堆中的小路，似乎因久未行走而荒廢。\n"]));
  
	setup();
}

void init()
{
  add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();
	if(arg != "古道")
		return 0;
	else {
		message_vision("$N"NOR"播開了雜草叢往西邊的古道摸索而去。\n", me);
		me->move(__DIR__"oldway1");
		return 1;
	}
}

