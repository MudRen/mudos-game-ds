//u/c/chiaa/world2/blackly_forest/vacancy2.c

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "林間空地");
        set("long", @LONG
這是林間的一小片空地,方圓不過數尺,兩旁除了青草綠樹,
不時可看見螻蟻之類的小昆蟲，也可聽得鳥叫蟲嗚,可以讓行走在森林的人,
在這裡暫時得到休息!在你東邊有一大片草叢,把你的視線視野都遮敝了,
在你前方的一簇雜草叢,隱約可聽到些微的聲音!!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "southwest" : __DIR__"parting",  //分歧路

        ]));
        set("item_desc",([
        "草叢":"一簇青綠草叢,頗有間隙能容人穿過去。\n",
        ]));

        set("no_clean_up", 0);
        set("outdoors","blackly_forest");
        setup();
}

void init()
{
        add_action("do_pass","pass");
}

int do_pass(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="草叢") return 0;
        message_vision(
"$N穿過了一大片的草叢。\n",
        me );
        me->move(__DIR__"nivi_entranceway");
        
        tell_room(
        environment(this_player() ),
        me->query("name")+"穿過草叢,走了過來。\n",me
);
        return 1;
}
