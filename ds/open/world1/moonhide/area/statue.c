#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(MAG"紫砂雕像"NOR, ({"statue"}) );
      set("long", @LONG 
一隻大型的巨鵰[0;1m�[1mA[0m旁邊有一個斷了右臂且披著一匹破
披風的人[0;1m�[1mA[0m左肩還背著一柄巨劍[0;1m�[1mA[0m不知道是誰 ? 
[這座雕像好像可以移動(move)的樣子?]
LONG
 );

        set_weight(9999999);
        set("unit", "座");
        set("no_sell", 1);
        set("no_give", 1);
        set("no_get", 1);
        set("no_drop", 1);

        setup();
}
void init()
{
    add_action("do_move","move");
}
int do_move(string arg)
{ 
    object me=this_player(),ob=this_object(),mobp; 
    if(ob->query_temp("moved")) return notify_fail("剛剛有人移動過了。\n");
    if(!arg||arg!="statue") return notify_fail("你要移動什麼?\n");
     switch (random(4) ){ 
                case 0:
      message_vision("$N將"+ob->name(1)+"移動了一點點！發出了『嘖嘖』的聲響..\n",me); 
      tell_object(me,"並沒發生什麼事...\n");
                      me->start_busy(2); 
                      ob->set_temp("moved",1); 
                      call_out("stop_moved",600,ob);
                      break;
               case 1:
      tell_object(me,"注意！\n");
      message_vision("$N將"+ob->name(1)+"移動了一點點！發出了『嘖嘖』的聲響..\n"
                     "突然一道巨大的黑影降臨....\n",me);
                     me->start_busy(3);
                     mobp=new(__DIR__"god-prey"); 
                     mobp->move(environment(this_player()));   
                     mobp->kill_ob(this_player()); 
                     ob->set_temp("moved",1); 
                     call_out("stop_moved",600,ob);
                     break;   
/*新增 By Jangshow */

               case 2:
       message("world:world1:vision","\n\n"+HIW"一陣狂風！掃蕩在古墓的外圍！巨禽神鵰由空中落下！\n\n"+NOR,users());
                     mobp=new(__DIR__"god-prey");
                     mobp->move(environment(this_player()));
                     mobp->set("level",70+this_player()->query("level")/6);   
                     mobp->kill_ob(this_player());
                     me->damage("hp",500);
                     ob->set_temp("moved",1); 
                     call_out("stop_moved",1000,ob); 
                     break;
                 }  
        return 1;
}
void stop_moved(object ob)
{
     if(!ob) return; 
     ob->delete_temp("moved");
}

