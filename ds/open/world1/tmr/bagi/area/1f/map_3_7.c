// Room: /open/world1/tmr/bagi/area/1f/map_3_7.c
#include <path.h>

inherit ROOM;

void create()
{
        set("short", "寒日洞一層");
        set("long", @LONG

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"map_4_6",
  "southeast" : __DIR__"map_4_8",
]));
        set("item_desc", ([ /* sizeof() == 2 */
                "活門" :"一道建造的十分隱密的機關活門。\n",
        ]));

        set("objects",([
                __DIR__"npc/jie":1,
                __DIR__"npc/trainee":2,
        ]));
        set("map_long", 1);
        set("current_light", 1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me =this_player();
        if(!arg || arg!="活門") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒有空做其它事。\n");
        message_vision("$N對著活門用力一推，忽然整個人隨著活門翻轉到另一邊去了。\n",me);
	me->move(TMR_PAST"bagi/cave1");
        tell_room(me,"一陣聲響過後，$N忽然出現在你面前。\n",({ me }));
        return 1;
        
}


