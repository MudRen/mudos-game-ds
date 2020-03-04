#include <ansi.h>
inherit ROOM;
string look_string();
void create()
{
  set ("short", HIR"封印之窟"NOR);
  set ("long", @LONG
這裡就是傳說中的封印之窟了，只有真正的勇者們才有資
格挑戰封印之窟的考驗，曾經進入封印之窟挑戰的人有千百人，
但到了最後活著出來的卻只有六個人，這六位勇士的名聲就因
此永遠的得到江湖上的歌頌。
LONG
);
        set("light",1);
        set("no_clean_up", 0);
        set("outdoors","land");
        set("exits", ([ /* sizeof() == 2 */
        "enter" : __DIR__"hole_2",
  ]));
        setup();
}
void init()
{
       object me;
       ::init();
       me=this_player();
       add_action("do_guard", "go");
       add_action("do_guard2","sneak");
}
int do_guard(string arg)
{
 if( (arg!= "enter") || !this_player()->visible(this_object()) ) return 0;

     {
     if(this_player()->query_temp("sexking/hole")>=1)
     { 
     message_vision(HIY"$N緊張的緩緩靠近封印之窟，突然被一道刺眼的光芒給罩了住，消失在所有人的眼前。\n"NOR,this_player());
     this_player()->delete_temp("the-hole");
     this_player()->move(__DIR__"hole_fly");
     this_player()->start_busy(4);
     call_out("flop1",3,this_player());
     return 1;        
     }
    else
 {
  message_vision(HIY"$N向前踏了一步，卻被莫名其妙的強大力量給轟了回來吐了幾口血。\n"NOR,this_player());
  return 1;
}
}
}
int do_guard2(string arg)
{
    if( (arg!= "enter") || !this_player()->visible(this_object()) ) return 0;
     {
     if(this_player()->query_temp("sexking/hole")>=1)
     { 
     message_vision(HIY"$N緊張的緩緩靠近封印之窟，突然被一道刺眼的光芒給罩了住，消失在所有人的眼前。\n"NOR,this_player());
     this_player()->delete_temp("the-hole");
     this_player()->move(__DIR__"hole_fly");
     this_player()->start_busy(4);
     call_out("flop1",3,this_player());
     return 1;        
     }
 else
  {
  message_vision(HIY"$N向前踏了一步，卻被莫名其妙的強大力量給轟了回來吐了幾口血。\n"NOR,this_player());
  return 1;
  }
}
}
void flop1(object me)
{
        if(!me) return;
        if (me->query_temp("the-hole")==1) return 0;
        tell_object(me,HIM"你漸漸的的恢復了知覺，醒了過來。\n");
        me->move(__DIR__"hole_2");
        tell_room(environment(me),me->query("name")+"突然從一道刺眼的光芒中走了出來\n"NOR,me);
        return;
}
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 3:
         case 2:        tell_object(me,"你有一種奇特的感覺..全身熱血沸騰..。\n");
                        return 1;
         
         case 1:
         case 0:        tell_object(me,"窟口裡吹出冷冷的風..令你忍不住顫抖起來。\n");
                        return 1;
default:       return 1;
        }
}

 


