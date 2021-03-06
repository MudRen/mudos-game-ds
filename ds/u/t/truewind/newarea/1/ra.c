#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "春風樓前院");
        set("long", NOR""+
"這兒是春風樓前院，只見滿地櫻花花瓣，好不美麗。這兒的櫻花\n"+
"樹種是公孫嬤嬤特地培植出來的，是故常年開花，是這一地區別緻的\n"+
"盛景之一。據說櫻花樹花瓣的香味對生病的人有特別的治療效果。\n"+
"    "HIM"櫻花樹"NOR"(Sakura tree)\n\n");

        set("current_light", 0);
        set("outdoors","land");
        set("item_desc",([
        "tree":"一排美麗的櫻花樹，看了真令人心曠神怡。\n",
        ]));
        set("exits", ([ /* sizeof() == 2 */
        "east" : "/u/t/truewind/workroom.c",
        "west" : __DIR__"rd",
        "north" : __DIR__"rb",
]));
        set("objects",([
        __DIR__"npc/s01" : 1,
]));

	setup();
}
       void init()
{
        add_action("do_move","move");
}
int do_move(string arg)
{
        object me=this_player(),flower;
        flower = new(__DIR__"obj/flower.c");
        if( arg !="tree" && arg !="櫻花樹" )
                return notify_fail("你要推什麼東西？\n");
        else if( !me->query_temp("rflower")) {
                message_vision("櫻花樹被這麼用力一推就掉了花瓣下來，$N順手接住。\n",me);
                me->set_temp("rflower",4);
                flower->move(me);
        } else {
                message_vision("$N用力一推沒推著樹，反而跌了個狗吃屎。\n",me);
                me->receive_damage("hp",10);
        }
        return 1;
}