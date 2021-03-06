#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW""BLK"嗜血鷹蝠"NOR, ({"eagle bat","bat"}) );
  set("long",@LONG
一隻巨大的蝙蝠，除了黑翼利牙之外，還有一雙銳利的鷹爪，專用來
抓開獵物血肉後，吸食其鮮血。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",25);
  set("attitude", "aggressive");
  set("gender", "雄性" );
  set("level",40+random(3));
  set("title",GRN"  妖獸 "NOR);
  set("limbs", ({ "頭部", "身體","雙翼","腳爪"}) );
  set("verbs", ({"bite","claw"}) );
  setup();
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper3");

}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if(!this_object()->visible(this_player()))
  {
    message_vision("\n$N發現了躲在暗處的$n，二話不說發動攻擊！\n\n"NOR,this_object(),this_player());
    this_object()->kill_ob(this_player());
  }
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  {
    message_vision("\n$N無聲無息地飛過$n，抓出一個皮開肉綻的傷口！\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(50)+50,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(3)+2));
    return 1;
  }
  return 0;
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
  ob->add("popularity",1);
  tell_object(ob,HIG"你得到 1 點聲望。"NOR);      
  ::die();
  return;
}
