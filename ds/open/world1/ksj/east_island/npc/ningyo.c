#include <ansi.h>
inherit NPC;

void create()
{
  set_name("人魚", ({"ningyo"}) );
  set("long",@LONG
它的上半身和人類一模一樣，而下半身卻是魚身，其貌不揚。看到人
魚是不吉的徵兆，但據說只要吃到人魚的肉便能長生不死喔！
LONG
);
  set("race", "human");
  set("unit","隻");
  set("age",200);
  set("gender", "男性" );
  set("level",25);
  set_skill("unarmed",40);
  set_skill("dodge",40);
  set_skill("parry",30);
  add("addition_armor",20);
  setup();
  carry_object(__DIR__"eq/ningyo-meat");
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
 
        switch( random(100) ) {
        case  0..2: new(__DIR__"eq/ningyo-necklace")->move(this_object());
        break;}
        ::die();
        return;
 }
