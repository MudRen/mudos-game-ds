#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "磐龍城水池前");
        set("long", @LONG
test .. 
LONG
        );

        set("item_desc",([
    "水池":"一淌水池，聽這兒的人說，丟點錢下去 . . . 可能會發生奇怪的事，只是沒人敢做罷了。\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "southeast" : __DIR__"room7",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_put","put");
}

int do_put(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="coin in 水池") return 0;
        if(!objectp(ring=present("coin",me) ) )
                return notify_fail("你沒有錢啊 ? \n");
        message_vision(HIY"$N丟了一點古幣到水池裡，高興的大喊 : @#$%^&*$%^&*#$&*@#(不知道在講什麼)。\n",me);
     message_vision(HIW "水池忽然透出白光，將$N團團圍住 . . . 不見了！！\n" NOR,me);
        me->start_busy(2);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"你到了磐龍城之禁地 . . . 神龍的大十字 。\n");
        me->move(__DIR__"room_6");
     tell_room(environment(me),me->query("name")+"忽然出現在這裡。\n",me);
        return;
}

