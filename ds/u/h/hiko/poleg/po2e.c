// 可以訂購去自訂料理...
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "泊浪村海產店");
        set("long", @LONG
這是泊浪村中的一家海產店，在這裡有許多的人在享用餐點，似乎
感覺起來還蠻有人氣的，海產店是在村裡有很好的口碑，因此熟客眾多
也打響了名號，在這裡有許多名人曾來過，例如天成的縣老爺以及軒轅
烈等，應該都是大家耳熟能詳的人物，上面是料理室，提供自製料理的
服務，而材料則得自己準備好了，若準備好便向店長訂購房間吧。
LONG
        );
        set("exits", ([
  "west" : __DIR__"po2",
  "up" : __DIR__"po2e-u",
]));
               set("item_desc",([
  "菜單" : "這是關於店裡的菜色，不過因為都是老客戶所以早已失去效力。\n",
]));
set("objects",([
__DIR__"npc/old-yang" : 1,
]));
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_goto",1);
        set("no_recall",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
}
 
void init()
{
  add_action("do_put","put");
  add_action("do_run","run");
}

int do_run()
{
  write("老楊對你說道：這位客倌，您還是出了店再用這個指令吧。\n");
  return 1;
}
int do_put()
{
  write("老楊對你說道：這位客倌，您還是出了店再用這個指令吧。\n");
  return 1;
}

int valid_leave(object me, string dir)
{
        int i, j=0;
        object *obs = all_inventory(me);
if( dir!="up")
 {  
   for(i=0; i<sizeof(obs); i++)
        {
        if(obs[i]->query("id") == "wealfish soup"  ||
           obs[i]->query("id") == "freshsha soup" )
         {
           message_vision("$N丟下一個$n。\n",me,obs[i]);
           destruct(obs[i]);
           j++;
         }
        }
       if(j) message_vision("老楊連忙把地上的東西收拾乾淨。\n",me);
       return ::valid_leave(me, dir);
 } 
if( dir=="up" && me->query_temp("cook") <=0 || !me->query_temp("cook") )
    { 
       return notify_fail("你還沒向店長付廚房使用費！\n");
    }   
 else 
   { 
     for(i=0; i<sizeof(obs); i++)
        {
        if(obs[i]->query("id") == "wealfish soup"  ||
           obs[i]->query("id") == "freshsha soup" )
         {
           message_vision("$N丟下一個$n。\n",me,obs[i]);
           destruct(obs[i]);
           j++;
         }
        }
       if(j) message_vision("老楊連忙把地上的東西收拾乾淨。\n",me);
       return ::valid_leave(me, dir);
    }
}






