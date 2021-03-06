#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "英雄之屋地下");
        set("long",@LONG
碰的一聲，你重重的跌落在此地，你觀望了一下四周，有許許多多
的武功密技在此，不過卻因為封在鐵櫃子中，也上了鎖，所以你沒辦法
閱讀，在東方的牆壁上留有一些些的字(word)。
LONG
        );
        set("exits", ([
        //"up" : "u/s/sdo/workroom.c",
	//"out": "/open/world1/tmr/area/hotel",
	"up":"/open/world1/cominging/area/herohouse1.c",
        ]));
        set("item_desc",([
        "word" : "牆壁上面依稀寫著："+HIW+"驅除韃虜，還我江山。\n"NOR,
        ]));
        set("no_clean_up", 0);
        set("light", 1);
        setup();
}

void init()
{
        add_action("open_hole","say");
}

int open_hole(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="還我江山" || str=="驅除韃虜")
	{
	object me;
	me=this_player();

	message_vision(
	HIG"\n$N低聲吟道："+str+"。\n"NOR
	HIG"\n$N聽到四周響起了一陣回聲。\n"NOR
	HIG"\n$N看到南邊的牆上出現了一個大洞。\n"NOR,me);

	set("exits",([
	//"up":"u/s/sdo/workroom.c",
        "south" : __DIR__"gravgate.c",
	"up":"/open/world1/cominging/area/herohouse1.c",
	]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
	set("exits", ([
        //"up" : "u/s/sdo/workroom.c",
	//"out": "/open/world1/tmr/area/hotel",
	"up":"/open/world1/cominging/area/herohouse1.c",
        ]));
	delete_temp("opened");
	::reset();
}