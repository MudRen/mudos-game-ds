#include <ansi.h>
#include <combat.h>
inherit NPC;

void create()
{
  set_name("大天狗", ({"big tengu","tengu"}) );
  set("long",@LONG
天狗中體型較大，年齡較長的天狗。
LONG
);
  set("race", "人類");
  set("unit","隻");
  set("age",60);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("tengu",1);
  set("level",46);
  set_skill("fork",60+random(15));
  set_skill("dodge",60+random(10));
  set_skill("parry",50+random(10));
  add("addition_armor",70+random(10));
  set("chat_chance", 7);
  set("chat_msg", ({
     (: random_move :),
     }));
  setup();
  set_living_name("tengu-war-tengu");
  switch( random(10) )
  {
    case 1: carry_object(__DIR__"eq/banlo-mask")->wear(); break;
    case 2: carry_object(__DIR__"eq/tengu-mask")->wear(); break;
    case 3: carry_object(__DIR__"eq/tengu-pants")->wear(); break;
    case 4: carry_object(__DIR__"eq/tengu-clog")->wear(); break;
  }
  switch( random(50) )
  {
    case  0..48: carry_object(__DIR__"eq/halbert")->wield(); break;
    case 49: carry_object(__DIR__"eq/hide-bone-dagger")->wield(); break;
  }
  carry_object(__DIR__"eq/tengu-cloth")->wear();
  carry_object(__DIR__"eq/whetstone");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if( this_player()->query("tengu-enemy") ) this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me || !target) return 0;
  if(me->is_busy()) return 0;

  if( random(target->query_dex()) < 3)
  {
    message_vision(HIC"\n$N左手拿出一把扇子朝著$n揮動，$n感受到強風襲來，幾乎站不住腳！\n\n"NOR, me, target);
    target->add_busy(1+random(2));
    return 1;
  }
  else if(!random(14))
  {
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
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
