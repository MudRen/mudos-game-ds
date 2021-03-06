#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIW""BLK"百目夢貘"NOR, ({"dream tapir","tapir"}) );
  set("long",@LONG
傳說中的魔物，專吸食人的噩夢，牠有著長滿黑色長毛的身體跟一隻
長長的鼻子，這隻食夢貘更擁有將獵物催眠進入惡夢的百眼。
LONG
);
  set("race", "beast");
  set("unit","隻");
  set("age",35);
  set("attitude", "aggressive");
  set("gender", "雄性" );
  set("level",35+random(5));
  set("title",GRN"  妖獸 "NOR);
  set("limbs", ({ "頭部", "身體","長鼻","尾巴"}) );
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
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(10))
  {
    message_vision("\n$N的眼睛引導$n進入無盡的噩夢中，$n一時表情痛苦地呆立著！\n\n"NOR, this_object(), target);
    target->add_busy(3);
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
