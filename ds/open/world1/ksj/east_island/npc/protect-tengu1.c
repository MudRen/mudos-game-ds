#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"守護天狗"NOR, ({"protect tengu","tengu","_PROTECT_TENGU1_"}) );
  set("long",@LONG
能力高於一般的天狗，負責守護天狗的首領，每位守護天狗都有其擅
長的能力。
LONG);
  set("race","monster");
  set("unit","隻");
  set("age",50);
  set("attitude", "aggressive");
  set("gender", "男性" );
  set("level",45);
  set_skill("fork",40+random(15));
  set_skill("dodge",40+random(10));
  set_skill("parry",30+random(10));
  add("addition_armor",60+random(10));
  set("chat_chance", 50);
  set("chat_msg",({
     (:command("defend black tengu"):),
     }) );
  set("chat_chance_combat",50);
  set("chat_msg_combat", ({
     (:command("defend black tengu"):),
     }) );
  setup();
  set_living_name("_NPC_PROTECT_TENGU1_");
}

int special_attack(object me,object target,int hitchance)
{
  object *inv;
      int damage, i;
  inv = all_inventory(environment(me));
  if(random(8)) return 0; 
  if(!me || !inv) return 0;
  message_vision("\n$N"HIW"飛向半空伸展雙翼，使出絕招"HIG"【天狗風】"HIW"！\n"+NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(100)+370-(inv[i]->query_shield())-(inv[i]->query_armor());
      if(damage < 0) damage=0;
      message_vision(HIR"$N被真空風壓劃過，造成 ("+damage+") 點的嚴重割傷！\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
      if( damage > 100)
        inv[i]->apply_condition("blooding", target->query_condition("blooding")+(random(2)+1));
    }
  }
  return 1; 
}
