//updated
#include <ansi.h>
inherit ITEM;
void end_war();
 string *animal=({"animal"});
string *place=({"zoo","zoo2","zoo3","zoo4",
        "zoo5","zoo6","zoo7","zoo11"});
void create()
{
        set_name(RED"制"NOR, ({ "controller" }) );
        set_weight(200000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long",
"你只是看到這個制上面有一個圖案\n"
         RED"　　　＼　　｜　　／\n"NOR
         RED"　　　　＼　｜　／　\n"NOR
         RED"　　　請　＼｜／　勿\n"NOR
         RED"　　　－－－－－－－\n"NOR
         RED"　　　亂　／｜＼　按\n"NOR
         RED"　　　　／　｜　＼　\n"NOR
         RED"　　　／　　｜　　＼\n"NOR
                        );
                set("value", 0);
                set("no_get",1);
                  set("no_sac",1);
        }
}
void init()
{
        add_action("typepush","push");
}
int typepush(string arg)
{
        int i;
        object me, ob1, ob2, obj;
obj=this_object();
        me=this_player();
if(obj->query_temp("open_war") ) return 0;
else {
  if(me->query_temp("quest/animal") )
   {
        if (arg != "controller") return 0;
     {
          me->delete_temp("quest/animal");
obj->set_temp("open_war",1);
        message("world:world3:vision",
HIW"\n  "+me->query("name") +HIW "觸發了ST。Cyberzoo的警報制.......\n"
HIW"         ST。Cyberzoo突然一片混亂.....\n"
,users() );
          ob1=new(__DIR__+"controller" );
        ob1->move("/open/world3/alickyuen/area/zoo19.c"); 
        for(i=0;i<=12;i++)
{
        ob2=new(__DIR__+"animal" );
        ob2->move("/open/world3/alickyuen/area/"+place[random(sizeof(place))] ); 
}
call_out("end_war",180);
      return 0;
     }
    }
  }
}
void end_war()
{
        object animal, obj;
obj=this_object();
          if(objectp(animal=find_living("reward-war-animal") ) )
{
       if(!environment(animal)) destruct(animal);
                  call_out("end_war",30);
        }
        else {
                message("world:world3:vision",
HIW"\n\n               動物園的管理人員壓制了這場混亂...\n\n"NOR
HIW"    並且關掉了警報鐘.....\n\n" NOR
                ,users() );
             obj->delete_temp("open_war");
destruct(obj);
        }       
        return 0;
}
