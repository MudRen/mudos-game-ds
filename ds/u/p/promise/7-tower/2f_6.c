#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", RED"七邪塔 "HIR"【火魅靈陣】"NOR);
  set ("long", @LONG
當你一踏入此地，就感覺慾火焚身，汗流浹背，在旁的鬼魅之火
不斷的燃燒，還有幽鬼火在旁不斷的環繞，感覺此地不只炎熱，更有
著不尋常的神物。
LONG
);
  set("exits", ([
  "south" : __DIR__"2f_5",
  "northeast" : __DIR__"2f_7",
   ]));
   set("objects", ([ /* sizeof() == 1 */

   __DIR__"npc/fire":4, 

]));
  set("no_clean_up", 0);
  
  setup();
 }


int valid_leave(object me, string dir)
{
    if( dir == "south" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("你被獄卒擋住了去路。\n");
     if( dir == "northeast" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("你被獄卒擋住了去路。\n");
    return ::valid_leave(me, dir);
}

