#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "巨石門");
        set("long", @LONG
none
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "enter" : __DIR__"room2",
  //"out"   : __DIR__"empty_room", 
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard":2,
]));
        set("outdoors","land");

        setup();
} 
/*****************************
int init()
{
    add_action("do_out","o");
} 
int do_out(string arg)
{
    object me=this_player();
    message_vision(HIG"\n『啊！！！』"+HIW"只聽見"+me->name(1)+"大聲的撕吼！！\n"NOR,users(),me);
    me->move(__DIR__"empty_room");  
    call_out("shown",3,me);
    return 1;
}

void shown()
{
    object me=this_player();
    message_vision(HIW"\n『碰！！！』的一聲，重重的摔在朝天樓外！\n"NOR,users(),me); 
    me->move("/open/world1/tmr/area/street4");
    me->die();  
    tell_object(me,"你重重地摔在空地上。\n");
    tell_room(environment(me),me->query("name")+"陡著忽然摔在你面前。\n",me);
    return;
} 
****************************/
