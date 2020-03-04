#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "虛擬石階");
        set("long", @LONG
似有似無的石階，遠接到天邊，看似並無盡頭，究竟是到哪一個世界的
通道？周微的空氣粒子竟然膨脹到看的見！原來這個看似石階的東西，就是
因為周遭的空氣膨脹所導致，又被一股無形的力量所牽引，造就了這個令人
嘖嘖稱奇的景觀。爬上石階(climb)。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"street5",
]));
set("light",1);

        set("outdoors","land");

        setup();
}
int init()
{
    add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object me=this_player(),ball;
    if(!me) return 0;
    if(me->query_temp("be_inflation") != 1)
    {message_vision(HIW"$N想踏上石階，沒想到卻撲了個空！\n"NOR,me); return 1; me->start_budy(2);}
    else{message_vision(HIW"$N慢慢踏上了石階，一步步的向上爬••\n"NOR,me); call_out("goup",1,me); return 1;}
}
void goup()
{ 
     object me=this_player();
     tell_object(me,"你努力的慢慢往上爬••感覺到空氣愈來愈稀薄••\n");
     me->move(__DIR__"room1"); 
     me->delete_temp("be_inflation",1);
     tell_room(environment(me),me->query("name")+"從石階爬了上來。\n",me);
     return;
}
