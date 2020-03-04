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
  "east" : __DIR__"2f_2",
   ])); 
   set("objects", ([ /* sizeof() == 1 */

   __DIR__"npc/fire":4, 

]));
  set("no_clean_up", 0);
  
  setup();
 }
 int room_effect(object me)
{
        switch(random(2))
        {
         case 0:
         write(HIR"在旁的鬼魅之火不斷的燃燒...\n"NOR);
         tell_object(me, HIW"你感覺非常的難受..。\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIR"你一不注意，兩道幽鬼火向你而撲.... \n"NOR);
         tell_object(me, HIB "你受到了一點小燒傷...。\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;
        }
}
int valid_leave(object me, string dir)
{
    if( dir=="east" && !userp(me) )
        return notify_fail("那裡只有玩家才能進去。\n");

    if( dir == "east" && objectp( present( "__GUARD__", this_object() )) )
        return notify_fail("你被獄卒擋住了去路。\n");

    return ::valid_leave(me, dir);
}

