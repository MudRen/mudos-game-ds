#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW"乾坤符"NOR,({"chan-kuan seal","seal"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","流傳已久的符咒。要去指定的地方，請打pray number，支援地方有:(1)朝天樓(2)天城中央(3)情城池門口(4)疾風門(5)神武教(6)八極門(7)步靈城中央(8)無砂鎮");
    set("value",50);
  }
  setup();
}

void init()
{
    add_action("do_move","pray");
}
int do_move(string arg)
{  
   object me = this_player();
   if(arg =="1" ) 
      {
 message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
          me->move("/open/world1/tmr/area/hotel"); 
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me);
           return 1;
         } if (arg == "2"){ 
          message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
          me->move("/open/world1/acme/area/hotel");
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me);
           return 1; 
         } if (arg == "3"){ 
           message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
          me->move("/open/world1/kkeenn/love/enter"); 
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me);
          return 1; 
         } if (arg == "4"){
         message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
         me->move("open/world1/cominging/area/flurry49");
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me);
           return 1;
         }   if (arg == "5"){ 
          message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
          me->move("/open/world1/acme/area/portal");
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me); 
          return 1;
         }   if (arg == "6"){ 
          message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
          me->move("/open/world1/tmr/area/s_house");
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me);
          return 1;
          }   if (arg == "7"){ 
          message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
          me->move("/open/world1/cominging/area/boo-lin");
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me);
          return 1;
          }   if (arg == "8"){ 
          message_vision(HIB"$N大聲喊著"NOR":"HIC"藍藍的天，賜我瞬移的神力！！\n"NOR,me);
          me->move("/open/world1/wu_sha_town/seacoun4");
          message_vision(HIW"一陣狂風，$N迎風而出。\n"NOR,me);
          return 1;

         }else{
          write("請重新輸入!!.....^^\n");
      return 1;
      }                   return 1;
}


