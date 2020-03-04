#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIW"�ǤѰ�@"HIR"�E"HIC"�p�Q�Y�ӤM"NOR, ({ "shouugan katana","katana" }) );
  set("long",@long
�j�ɮ٪Z�ѬӦb��ɡA�e���n���«����ɡA��M���@���Q�����ӡA��
�Q�����ۤv�O��կ��c���Ϫ̫K�S���h�A����d�U���o��ӤM�K����
�W�����p�Q�Y���C�ǻ�  ���M�@�̬��j�ӤѰ�A�����_�~�N���M�K�C
�p�Q�Y��������������A�b����������A�`������������C
long);      
  set_weight(1450);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value",30000);
    set("volume",3);
  }
  set("rigidity",1200);
  set("limit_skill",60);
  set("limit_lv",40);
  set("weapon_prop/str",1);
  set("weapon_prop/con",2);
  set("weapon_prop/dex",2);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(68);
  set("wield_msg",HIC"$N�N$n"HIC"�q�M�T���ޥX�A�q�M�b���{�{�B�{���Υ����C\n"NOR);
  set("unwield_msg","$N�N�⤤��$n��^�M�T�A�o�X--��--�@�n�M�T�C\n");
  setup();
}


void attack(object me, object victim)
{
  int damage,def;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_dex() > 40 && random(10)<3 )
  {
    message_vision(HIC"\n�p�Q�Y�ӤM"HIW"�a��"HIY"$N"HIW"�����Ϋ�R�A"
                  +"�M���H�v�ۤƱq�|�P�A�٨�$n"HIW"���W�D�D�D\n"NOR,me,victim);
    damage += me->query_skill("blade")+me->query_str()+random(100);
    def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
    def = def/3;
    if(damage-def>0 && random(10)>4)
    {
      damage=damage+random((damage-def));
      message_vision(HIR"�M���E���A$N"HIR"�uı�����@�h�A"
                    +"�A���H�ۥs�n�q�x�b�Ť��I�I("+damage+")\n"NOR,victim);
      victim->receive_damage("hp",damage, me);
    }
    else message_vision(HIG"$N"HIG"�������{�k���A���n�k�X�F��դ��~�C\n"NOR,victim);
  }
  return;
}
