#include <ansi.h>
#define ENTER_ROOM "/open/world1/alickyuen/match/entrance"

inherit ROOM;

int doll_check(object me);

void create()
{
        set("short", "MOB測試區域出口");
        set("long", @long
這裡是測試出去的出口兼入口，凡是要進入或出去，都得從此出
進出。要離開請打"out"，要索取測試替死娃娃的話，請往替身小紅
帽那索取。
long);
        set("light", 1);
        set("no_fight", 1);
        set("no_kill", 1);
        set("no_cast", 1);
        set("objects", ([
                __DIR__"doller" : 1,
        ]));
   set("exits", ([ /* sizeof() == 2 */
  "out" : "/open/world1/tmr/area/hotel",  "east" : "/u/p/promise/testroom1",
])); 
        setup();
}

void init()
{
        object me = this_player();

        if( !me ) return;

        add_action("doll_check", "out");

                return;

        doll_check(me);
}

int doll_check(object me)
{
        object doll;
        me = this_player();
        message_vision(HIW"娃娃小紅帽正在檢查$N身上有沒有測試用的替死娃娃.....\n"NOR, me);
        if( objectp(doll = present("test doll", me) ) )
        {
                message_vision(HIW"娃娃小紅帽把"+me->query("name")+"身上的"NOR+doll->query("name")+HIW"拿走了。\n"NOR, me);
                destruct(doll);
        } 
        else
        } 
                message_vision(HIR+me->query("name")+"身上沒任何東西，突然間被娃娃小紅帽踢出去了。\n"NOR, me);
                me->move("/open/world1/tmr/area/hotel");
        } 
        return 1;
}

