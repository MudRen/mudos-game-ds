#include <ansi.h>
inherit NPC;

void create()
{
         set_name("帝狼守護神",({"guard wolf","wolf"}) );
          set("title","百年神獸");
  set("long",@LONG
牠就是妖劍神用來守住天妖封印的神獸
LONG
);
   set("attitude", "aggressive");

set("combat_exp",50000);
set("max_hp",15000);
set("max_ap",1000);










                 

  set("race", "beast");
  set("unit","隻");
  set("age",100);
  set("level",45);
  set("limbs", ({ "頭部", "腹部","胸部","爪子","尾巴" }) );
  set("verbs", ({ "bite","claw" }) );
  setup();
  add_money("coin",1100);
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
  HIG"\n【天妖在世】" +HIW"天妖大笑：「哇哈哈哈，"+ob->name(1)+"幹的好阿，把我的封印解開了。\n\n"+NOR
        ,users());
        ob->add("popularity",3); //聲望
        ::die();
        //destruct(this_object());
        return;
}

