#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "小墓室");
        set("long",@LONG
這一間墓室比起外面的墓室明顯的小了很多，不過仍然算是十分
的寬敞。角落有一個托盤，托盤上好像有東西在那一樣。不過越靠近
那個東西，感覺身體四周的空氣流動速度越來越快了。
LONG
        );
        set("exits", ([
        "west" : __DIR__"grav1.c",
        ]));
        set("item_desc",([
        "托盤" : "一個很大的盤子，上面放著一雙脛甲，好像可以拿起來(get)。\n",
        ]));
        set("light", 0);
        setup();
}

void init()
{
	add_action("get_leggingss","get");
}

int get_leggingss(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="leggings" || str=="脛甲")
	{
	object me,b;
	me=this_player();

	message_vision(
	HIC"\n$N正打算拿起盤子裡的脛甲時，脛甲化作一陣狂風消失了。\n"NOR
	HIC"\n一隻守護獸伴隨著狂風出現在$N的面前。\n"NOR,me);

	b=new(__DIR__"obj/npc/wind_beast.c" );
	b->move(__DIR__"grav3.c" );
	
        set("item_desc",([
        "托盤" : "一個很大的盤子，上面什麼東西也沒有。\n",
        ]));

	set_temp("opened",1);
	return 1;
	}
}
void reset()
{
	delete_temp("opened");
	set("item_desc",([
        "托盤" : "一個很大的盤子，上面放著一雙脛甲，好像可以拿起來(get)。\n",
        ]));
	::reset();
}