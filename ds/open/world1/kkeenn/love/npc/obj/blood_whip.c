#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;
void create()
{
  set_name( HIR"���]�@"NOR , ({ "blood dream whip","whip" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@���q�餣�ѦۥD���o�X�@�ѱ����@�l�A�ǻ��O\n���k�P�L�j�Ԧ��]�ɡA�H���]����ҹL���@�l�C\n");
    set("material", "gold");
    set("value",8500);
    set("weapon_prop/str",2);
    set("weapon_prop/dex",2);
  }
        set("replica_ob", __DIR__"whip5.c");
        set("wield_msg","$N�@����¶�b�y����$n�A�٨����@�ѱj�P������q$N�����W�z�o�X�ӡI\n");
        set("unwield_msg", "$N�H��@�ݡA�N�⤤��$n��^�y���C\n");
  init_whip(65);
  setup();
}

void attack(object me,object victim)
{
  int i;
  object *enemy;

  ::attack();
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(3)) return;
  if(me->query("ap") < 40) return;
message_vision(HIG"\n$N���G�O�P����F�⤤$n"HIG"������A�@�ѱ��N������Y�m���Ƨ����n�I\n\n"NOR,me,this_object());

  enemy = me->query_enemy();
  for(i=0;i<sizeof(enemy);i++)
  {
    if(userp(enemy[i])) COMBAT_D->do_attack(me,enemy[i],me->query_temp("weapon"),4);
      else COMBAT_D->do_attack(me,enemy[i],me->query_temp("weapon"),random(3)+2);
  }
  message_vision("\n",me);
  me->receive_damage("ap", 30, me);
  return;
}
