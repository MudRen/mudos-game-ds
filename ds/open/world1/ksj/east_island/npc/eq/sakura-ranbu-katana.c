#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
  set_name(HIM"��ûR"NOR, ({ "sakura-ranbu katana","katana" }) );
  set("long",@long
�H����M�T�����M�A�M�b�e�{���R����᯾�A�@�몺��y�M�C���覡
�õL�k�s�@���X�A�ڻ����H  ��t�D�������L���t�Z�ɤ@�M��٦V
�@������A�⤤�ӤM�~�M���n���_�A��O�b�𤤵o�{���M�C
long);      
  set_weight(1650);
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
  set("limit_lv",33);
  set("weapon_prop/int",2);
  set("weapon_prop/con",1);
  set("weapon_prop/bio",-1);
  set("replica_ob",__DIR__"ya-katana");
  init_blade(63);
  set("wield_msg","$N�w�w�ޥX$n�A�M���M�Ӧb�|�P���p��������Ƹ��C\n"NOR);
  set("unwield_msg","$N�N�⤤��$n��^�M�T�A�o�X--��--�@�n�M�T�C\n");
  setup();
}

void attack(object me, object victim)
{
  int damage,def;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_int() > 40 && random(10)<3 )
  {
    message_vision(HIM"\n�Ť���M�ƤU����ä�b$n���P��ۻR�A�B�ͤF$n�����u�D�D�D\n"NOR,me,victim);
    damage += (me->query_skill("blade"))/2+me->query_str()+random(50);
    def += victim->query_skill("parry")+victim->query_skill("dodge")+victim->query_dex()+victim->query_con();
    def = def/4;
    if(damage-def>0 && random(10)>4)
    {
      damage=damage+random((damage-def));
      message_vision(HIR"$N��M�P��@�}�@�h�A����w�Q�����٤��A�A�媽�y�I�I"HIR"("+damage+")\n"NOR,victim);
      victim->receive_damage("hp",damage, me);
      me->receive_damage("ap",30);
      damage=damage-random(100)+30;
      if(me->query_dex() > 70 && !random(5) && damage >0)
      {
        message_vision(HIR"�M���ֳt�j�۰f�١A$N���I��S�Q�M�b���L�I�I"HIR"("+damage+")\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
        me->receive_damage("ap",30);
      }
      damage=damage-random(100)+10;
      if(me->query_dex() > 90 && me->query_str() > 90 && !random(5) && damage>0)
      {
        message_vision(HIR"�M���ֳt�j�۰f�١A$N���I��S�Q�M�b���L�I�I"HIR"("+damage+")\n"NOR,victim);
        victim->receive_damage("hp",damage, me);
        me->receive_damage("ap",30);
      } 
    }
    else
    { 
      message_vision(HIW"�@�D�M���A�V$N�A���O���F�@�I�S���R���C\n"NOR,victim);
      me->receive_damage("ap",20);
    }
  }
  return;
}
