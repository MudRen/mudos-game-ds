#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short", CYN"青龍閣"NOR);
  set ("long","
這就是火魅靈所在處─「"CYN"青龍閣"NOR"」！！
在這旁邊有道"HIY"生鏽的破門"NOR"，需有人大力的推打才開的了！！    
在此生鏽的門旁邊還有許\多"HIB"鬼魂"NOR"在此徘徊，請小心！！  
\n"NOR);
  set("exits", ([
  "southwest" : __DIR__"f7", 
  ])); 
     set("item_desc",([
     "生鏽的破門": HIW"\n此門以生鏽，需要龐大的力量才能推開(push)它。\n"NOR,
        ]));
  set("no_clean_up", 0);
  
  setup();
 } 
void init()
{
        add_action("do_push","push");
}

int do_push(string str)
{

object me;
me=this_player();
     if(this_object()->query_temp("opened") != 0) return 0;
     if(str=="門" || str=="生鏽的門")      if(me->query("class1") != "八極門") return notify_fail(HIR"護衛喝道：站住！這裡不是你這外人可以進入的地方！？\n"NOR);
        message_vision(
HIC"\n\n你虎喝一聲，氣運雙掌, 使出絕技「猛虎硬爬山」，狠狠地擊向生鏽的門！！\n\n"HIR"生鏽的門被$N"HIR"狠狠的擊中，應聲而破！！
"NOR"(  生鏽的鐵門"HIR"損壞度達到１００％。 "NOR" )\n"NOR,me);
         set("exits",([
        "southwest":__DIR__"f7",
        "enter":__DIR__"w1", 
 ]));
         set("long","           
這就是火魅靈所在處─「青龍閣」！！
在這旁邊有道生鏽的破門，需有人大力的推打才開的了！！    
在此生鏽的門旁邊還有許\多鬼魂在此徘徊，請小心！！  
"HIR"\n\t\t有人破門而入了∼∼∼
"NOR);            
        set("item_desc",([
        "生鏽的門":"生鏽的門已被打破。\n",
        ]));
                  
        set_temp("opened",1); 
                       return 1;
        }
void reset()
{
        set("long","
這就是火魅靈所在處─「"GRN"青龍閣"NOR"」！！
在這旁邊有道"HIY"生鏽的破門"NOR"，需有人大力的推打才開的了！！    
在此生鏽的門旁邊還有許\多"HIB"鬼魂"NOR"在此徘徊，請小心！！  
\n"NOR);
        set("item_desc",([
     "生鏽的門": HIW"\n此門以生鏽，需要龐大的力量才能推開(push)它。\n"NOR,
       
        ]));

        set("exits", ([
        "southwest":__DIR__"f7.c",
             ]));
        delete_temp("opened");
        ::reset();
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
       if( dir=="enter" && !userp(me) )
                return notify_fail("那裡只有玩家才能進去。\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("這裡太過擁擠了，你走不過去。\n");
        return ::valid_leave(me, dir);
}

