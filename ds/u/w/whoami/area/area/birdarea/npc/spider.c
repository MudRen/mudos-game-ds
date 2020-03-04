#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIR"噬血"NOR+MAG"蜘蛛"NOR, ({"blooding spider","spider"}) );
  set("long",@LONG
這個噬血蜘蛛是九尾妖狐的部下，幫九尾妖狐鎮守第一關•
LONG);
  set("race", "beast");
  set("gender", "雄性");
  set("unit","隻");
  set("age",12); 
  set("max_hp",30000);  set("level",36+random(5));
  set("title",HIW"守護者"NOR);
  set("limbs", ({ "頭部", "身體","前肢","後肢","背部" }) );
  set("verbs", ({ "bite"}) );
  set("combat_exp", 12000);
  add("addition_armor",20); 
  setup();
}

void die()
{
        object me=this_object();
        object ob,obj;

        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        { 
                ::die();
                return;
        }
        message_vision("\n因為$N的死亡，這個房間似乎又多了條通路了！\n",me);
        "/open/world1/whoami/birdarea/fox18.c"->add("exits", 
([ "enter" :  "/open/world1/whoami/birdarea/fox19.c"]));
           ::die();
           return;
}        


