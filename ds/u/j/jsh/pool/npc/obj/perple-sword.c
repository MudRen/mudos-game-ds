#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
  set_name(HIY"���שw���C"NOR , ({ "perple-light sword","sword" }) );
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "���שw���C�A�D�j�^���ܹFù�P����E�ԫᤧ�򪫡A����O�򪫡A�i�Q�Ӫ��C\n");
    set("material", "gold");
    set("value",10000);
    set("weapon_prop/str",3);
    set("weapon_prop/con",2);
    set("weapon_prop/dex",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/dodge",10);
    set("weapon_prop/sword",10);    
    set("replica_ob",__DIR__"perple-sword2");
}
    set("wield_msg",HIW"$N��X$n�A�������_�@�}�}�j���I\n"NOR);
    init_sword(63+random(3)); 
  setup();
}
void attack(object me, object victim)
{
    int damage,tk_one;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("sword") > 70 && me->query_str() > 30 && random(10)<3 )
    {
      message_vision(HIW "\n�y�F�z���@�n�I$N�⤤��"HIY"���שw���C"HIW"�z�X�|�m�����A�����ܦV$n�������I�I\n" NOR,me,victim);
      damage += me->query_skill("sword")+me->query_str()+random(40);
      tk_one += victim->query_skill("parry")+victim->query_dex();
      tk_one = tk_one/3;
      if(damage-tk_one>0 && random(10)>5)
      {
        damage=damage+random((damage-tk_one));
        message_vision(HIR "$N�g�~�@�n�I��ۡE�E�����K�y�U���A��E�E\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else message_vision(HIG "$N�ਭ����, �{�}�F��ت��������C\n"NOR,victim);
    }
    return;
}

