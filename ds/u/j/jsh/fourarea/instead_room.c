#include <ansi.h>
inherit ROOM;

void show(object me);

void create()
{
        set("short", "囑之房");
        set("long", @LONG
test
LONG
        );

        set("item_desc",([
        "銅鏡":"一面古老的銅鏡，上面還覆蓋著薄薄的黃土，看來年代久遠。\n",
        ]) );
        set("exits", ([ /* sizeof() == 1 */
          "home" : "/u/m/moonhide/workroom",
        ]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_instead","instead");
}

int do_instead(string arg)
{
        object me,ring;
        me=this_player();
 
      if(!arg || arg!="tear to mirror") return notify_fail("你要照什麼?\n");
        if(!objectp(tear=present("ice of tear",me) ) )
                return notify_fail("你要拿什麼照鏡子 ? \n");
        message_vision(HIC"$N將手中的冰之淚指\向銅鏡，一陣藍光射出，打向銅鏡。\n",me);
     message_vision(HIY"藍光高拋到天際，圍成一半月型，速下套住$N� . .！！\n" NOR,me);
        me->start_busy(5);
        call_out("show",3,me);
        return 1;        
}

void show(object me)
{

        tell_object(me,"你站在月之神殿前。\n");
        me->move(__DIR__"未完.c");
     tell_room(environment(me),me->query("name")+"忽然站在你的面前。\n",me);
        return;
}

