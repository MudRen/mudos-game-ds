#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", YEL"百蝦閣"NOR);
  set ("long","眾海鮮將士奮不故身的守護的神聖境地，在旁有兩個石雕，分別
代表『忠誠』與『責任』，想必他們的將領也是遵循這兩種精神來維
持他將領的地位吧。\n"NOR);
  set("exits", ([
  "east" : __DIR__"w14", 
  ])); 
     set("item_desc",([
     "破燈": HIW"\n此破燈似乎很久沒有點燃(fire)了？\n"NOR,
        ]));
  set("no_clean_up", 0);
  
  setup();
 } 
void init()
{
        add_action("do_fire","fire");
}

int do_fire(string str)
{

object me;
me=this_player();
     if(this_object()->query_temp("fired") != 0) return 0;
             if( str !="破燈" && me->query("class1") != "神武教" )
       return notify_fail("what?\n"NOR);
 message_vision("你雙手合十，喃喃自語道：「"HIG"天地合德，日月合明，四時合序，鬼神合火以滅敵。"NOR"」
\t突然你手上烈焰衝天,祭起一道『"HIR"神武真火"NOR"』直燒向破燈！！\n\t( "HIR"破燈就此燃燒起來了！！"NOR" )\n
\t\t"HIW"突然前方出現了一條明亮的路！！
\n"NOR,me);
         set("exits",([
        "east": __DIR__"w14",
        "climb":__DIR__"d1", 
 ]));
         set("long","           
眾海鮮將士奮不故身的守護的神聖境地，在旁有兩個石雕，分別
代表『忠誠』與『責任』，想必他們的將領也是遵循這兩種精神來維
持他將領的地位吧。\n\t"HIY"前方以亮起了一處路線！！\n"NOR);            
        set("item_desc",([
        "破燈":"此燈已被點著。\n",
        ]));
                  
        set_temp("fired",1); 
                       return 1;
        }
void reset()
{
   set ("long","
眾海鮮將士奮不故身的守護的神聖境地，在旁有兩個石雕，分別
代表『忠誠』與『責任』，想必他們的將領也是遵循這兩種精神來維
持他將領的地位吧。\n"NOR);
        set("item_desc",([
       "破燈": HIW"\n此破燈似乎很久沒有點燃(fire)了？\n"NOR,
   
        ]));

        set("exits", ([
        "east": __DIR__"w14",
             ]));
        delete_temp("fired");
        ::reset(); 
}int room_effect(object me)
{
        switch(random(2))
        {


         case 0:
         write(HIC"陣陣海浪襲擊你全身....\n"NOR);
         tell_object(me, HIC"你感覺身體遲鈍了些..。\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIB"海浪滔滔襲擊你... \n"NOR);
         tell_object(me, HIB "你被海浪刺了些...。\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;
        }
}

