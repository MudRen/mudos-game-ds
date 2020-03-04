#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit WHIP;
void create()
{
  set_name(HIC"�s���@"NOR , ({ "dragon king whip","whip" }) );
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�@���q�餣�ѦۥD���o�X�@���Q���@�l�A�ǻ��O\n�����P�L�j�ԫC�����s�ɡA�H�C�s�����[�����@�l�C\n");
    set("material", "gold");
    set("value",9500);
    set("weapon_prop/str",2);
    set("weapon_prop/con",1);
    set("weapon_prop/dex",1);
  }
        set("replica_ob", __DIR__"whip5.c");
        set("wield_msg","$N�@����¶�b�y����$n�A�٨����@�ѱj�P���Q��q$N�����W�g��X�ӡI\n");
        set("unwield_msg", "$N�H��@�ݡA�N�⤤��$n��^�y���C\n");
  init_whip(70);
  setup();
}
void attack(object me, object victim)
{
    int damage,def;

    ::attack();
    if(!me) return;
    if(!victim) return;

    if(me->query_skill("whip") > 50 && me->query_dex() > 20 && random(10)<3 )
    {
      message_vision(HIG "\n���M$N�⤤�s���@�j�񲧱m, �@�D�j�P���C���q�s���z�g�ӥX, ���V�ĤH�I�I\n" NOR,me,victim);
      damage += me->query_skill("whip")+me->query_str()+random(30);
      def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
      def = def/3;
      if(damage-def>0 && random(10)>5)
      {
        damage=damage+random((damage-def));
        message_vision(HIR "$N�����p�����, �Q�C���g�ۥ����I\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
      }
      else message_vision(HIG "$N�^���@��, ��n�׶}�F���P�R���C���C\n"NOR,victim);
    }
    return;
}

