#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "雲端階梯");
        set("long", @LONG
你正在一處雲端階梯上，腳下踩的是團團白花花的雲朵，你也不清楚
人怎麼可能站在雲上，這的確是個不解之迷。雲端階梯往上可以通往雲端
廣場，往下是處平台，可以跳回(jump down)到地面。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "up" : __DIR__"way4d",
]));
        set("no_clean_up", 0);
        set("outdoors", "land");
        set("current_light", 1);

        setup();
}

int do_jump(string arg)
{
    object me;
        me=this_player();
 
        if(me->is_busy() || me->is_fighting()) 
                return notify_fail("你正忙著。\n");
        if(!arg || arg!="down") 
                return 0;
        message_vision(HIW "$N念了聲阿彌陀佛，閉上眼睛提氣就往下跳去。\n"NOR,me);
        me->start_busy(2);
        me->move(__DIR__"up-room");
        return 1;        
}


void init()
{
        add_action("do_jump","jump");
}

