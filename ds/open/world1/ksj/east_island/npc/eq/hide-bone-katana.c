#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(MAG"�c���M"HIR"�E"NOR""GRN"����"NOR, ({ "hide-bone katana","katana" }) );
  set("long",@long
�ǻ��c���Ɒ�ܨӪ��W�M�M�b�H�H�����M�`�ΤM�T�A�s���o��c���M
�A�ѩ�B�󨸴c��©�����Ҥ��A�M�b�����a������A�����O�H���ߪ�
���M�A�M�������ë���μɩѪ��O�q�C
long);      
  set_weight(2550);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",5);
  }
  set("rigidity",1200);
  set("limit_skill",60);
  set("limit_lv",42);
  set("weapon_prop/str",3);
  set("weapon_prop/int",-3);
  set("weapon_prop/bio",1);
  set("weapon_prop/bar",-1);
  set("replica_ob",__DIR__"peach-wind-sword");
  init_blade(67);
  set("wield_msg",HIC"$N�ޥX�y����$n�A���M��ı�����ܱo�u�񨸴c�C\n"NOR);
  set("unwield_msg","$N�N�⤤��$n���^�M�T�A�uı�o�߱����P���֡C\n");
  setup();
}


void attack(object me, object victim)
{
  int damage,def;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_bio() > 7 && random(10)<3 )
  {
    message_vision(MAG"\n�c���M�E�����M�b������j���A���o�X�`�񪺰���A$N"MAG"��M�Q�@�ѫ�\n"
      +"�몺�Pı�R�������A�y��u��a�N�c���M�E�����٦V$n�C\n"NOR,me,victim);
    damage += me->query_skill("blade")+me->query_str()+random(100);
    damage = damage/3;
    message_vision("$N"HIR"���M�B�k�h�����A�y�X�����G�I�I("+damage+")\n"NOR,victim);
    victim->receive_damage("hp",damage, me);
    victim->apply_condition("blooding",victim->query_condition("blooding")+(random(2)+1));
    victim->apply_condition("poison",victim->query_condition("poison")+(random(2)+1));
  }
  return;
}
