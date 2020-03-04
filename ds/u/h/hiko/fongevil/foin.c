#include <ansi.h>
inherit ROOM;
string query_test();
int testing=1;
void create()
{
        set("short","遺跡大廳");
        set("long",@LONG
你終於進到遺跡的內部了，裡面的樣子和擺設極為古老，看起來似乎
很久沒人來過了，因此讓你感到十分奇特，隱約看起來這裡有著很強大的
陰冷氣息，想必是封印了了不得的東西，牆壁上掛了一個匾額。
LONG);
        
        set("item_desc", ([
        "匾額" : "封印邪物之地，無把握之人請快退去\n",
        ]));
        set("exits", ([
            "leave" : __DIR__"fodoor",
        ]));
        set("no_clean_up", 0);        
        setup();
}

void init()
{
        add_action("do_beat","beat");
        add_action("do_select","select");
        call_out("wel_in",0);
}

int do_select(string arg)
{
         object me,ob;
         me=this_player();
         ob=this_object();
         if(!arg) return notify_fail("你想選什麼?\n");
         if(arg=="fire" && !query("test_fire"))
         {
           message_vision(HIR"$N選擇了火之測驗，化作一道紅光消失了\n"NOR,me);        
           me->move(__DIR__"fofire_1");
           testing=2;
           ob->set("test_fire",1);
           return 1;        
          }      
          if(arg=="wind" && !query("test_light"))
         {
           message_vision(HIY"$N選擇了光之測驗，化作一道閃光消失了\n"NOR,me);        
           me->move(__DIR__"folight_1");
           testing=3;
           ob->set("test_light",1);
           return 1;
         }
         if(arg=="water" && !query("test_water"))
         {
           message_vision(HIB"$N選擇了水之測驗，化作一道藍光消失了\n"NOR,me);        
           me->move(__DIR__"fowater_1");
           testing=4;
           ob->set("test_water",1);
          return 1;
         }               
         if(arg=="fantasy" && !query("test_fantasy"))
         {
           message_vision(HIM"$N選擇了幻之測驗，化作一道虹光消失了\n"NOR,me);        
           me->move(__DIR__"fofantasy_1");
           testing=5;
           ob->set("test_fantasy",1);
           return 1;
         }   
         return notify_fail("有人在測驗中了唷\n");
}        
 
void wel_in()
{        
         object me;
         me=this_player();
         if(testing!=5)
         {
          tell_object(me,"你聽到了一個聲音︰ 請選擇(select)要去哪個試驗\n");
          tell_object(me,HIG"-----"+query_test()+HIG"-----"NOR"\n");          return;
         }
         tell_object(me,"你聽到一個聲音︰你來晚了..都有人在測驗了\n");
         tell_object(me,"離去吧，等待下次的機會\n");
         me->move(__DIR__"fodoor");
         return;
}

string query_test()
{
         string tesg=""; 
         switch(testing){
          case 1 : tesg+=HIR+"火(fire)"+NOR+",";
          case 2 : tesg+=HIY+"光(light)"+NOR+",";
          case 3 : tesg+=HIB+"水(water)"+NOR+",";
          case 4 : tesg+=HIM+"幻(fantasy)"+NOR;
       
       }
       return tesg;
}



