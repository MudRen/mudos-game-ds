#include <ansi.h>
inherit NPC;

void create()
{
  set_name(GRN"青鱗岩蟒"NOR, ({"green snake","snake"}) );
  set("long",@LONG
身長約若２５尺，全身青綠的蛇鱗像岩石般嶙嶇不平，當牠盤曲時活
像一塊長滿青苔的岩石，雖然沒有毒性，卻長滿尺餘長的大小尖牙，
掠食小牛大小的動物可以說輕而易舉。
LONG);
  set("race", "beast");
  set("unit","隻");
  set("age",45);
  set("gender", "雄性" );
  set("level",27+random(4));
  set("title",HIW"  奇獸 "NOR);
  set("limbs", ({ "頭部", "身體","尾巴" }) );
  set("verbs", ({ "bite" }) );
  add("addition_armor",25+random(5));
  set("chat_chance", 10);
  set("chat_msg", ({
     (: random_move :),
  }));
  setup();
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(6))
  {
    message_vision(GRN"\n青鱗岩蟒"HIR"的利牙劃過$n，割出數條皮開肉綻的傷口！\n\n"NOR, this_object(), target);
    target->receive_damage("hp",random(100)+100,me);
    target->apply_condition("blooding", target->query_condition("blooding")+(random(5)+5));
    return 1;
  }
  return 0;
}

int receive_damage(string type,int cost)
{
  object ob,target;
  int i;
  ob = this_object();
  target = this_player();
  ::receive_damage(type,cost,target);
  return 0;
}

void init()
{        
  ::init();
  switch( random(10) )
  {
    case 0:
         say(GRN"青鱗岩蟒"NOR"鑽入草叢中，消失不見了。\n");
         destruct(this_object());
         break;
  }
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
  switch( random(99) )
  {
    case  0..9: new(__DIR__"eq/green-snake-waist")->move(this_object());
          break;
  }
  ::die();
  return;
}
