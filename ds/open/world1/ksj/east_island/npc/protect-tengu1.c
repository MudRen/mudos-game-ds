#include <ansi.h>
inherit NPC;

void create()
{
  set_name(HIC"�u�@�Ѫ�"NOR, ({"protect tengu","tengu","_PROTECT_TENGU1_"}) );
  set("long",@LONG
��O����@�몺�Ѫ��A�t�d�u�@�Ѫ�������A�C��u�@�Ѫ��������
������O�C
LONG);
  set("race","monster");
  set("unit","��");
  set("age",50);
  set("attitude", "aggressive");
  set("gender", "�k��" );
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
  message_vision("\n$N"HIW"���V�b�Ŧ��i���l�A�ϥX����"HIG"�i�Ѫ����j"HIW"�I\n"+NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if( living(inv[i]) && userp(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(100)+370-(inv[i]->query_shield())-(inv[i]->query_armor());
      if(damage < 0) damage=0;
      message_vision(HIR"$N�Q�u�ŭ������L�A�y�� ("+damage+") �I���Y���ζˡI\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
      if( damage > 100)
        inv[i]->apply_condition("blooding", target->query_condition("blooding")+(random(2)+1));
    }
  }
  return 1; 
}
