#include <room.h>
inherit ROOM;
void create()
{
 set("short","往山腰的路上");
 set("long",@LONG
這邊有一間小茶館, 用棚架搭著, 或許你可以進去看看,
休息休息. 旁邊有些江湖人士, 也許你可以和他們打聽一下
看這是哪裡? 如果你視力夠好, 便能看到山頂似乎有一棟建
築物.
LONG
    );
 set("exits",([ "west":__DIR__"mountdown2",
                "south":__DIR__"mountdown4",
                "southeast":__DIR__"mountdown5",
		"northeast":__DIR__"jungle1",]));
 set("no_clean_up", 0);
 setup();
}
void init()
{
	add_action("do_enter","enter");
}
int do_enter(string arg)
{
	object me;
	me=this_player();
	if (arg != "茶館" && arg != "小茶館") tell_object(me,"你要進去哪裡?\n");
	else 
	{
		message_vision("$N掀開了茶館的布幔, 走進茶館中休息。\n",me);
		me->move(__DIR__"rest_tea");
		return 1;
	}
}
