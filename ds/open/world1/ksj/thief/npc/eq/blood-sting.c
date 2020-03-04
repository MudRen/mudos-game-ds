#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
  set_name(HIR"���"NOR,({"blood sting","sting"}));
  set("long",@LONG
�o�O�@���A���⪺���v�C��A�ݨ�o�⬽�r���Z���ɤ��T�N�����y�A
��봲�o�X�Ӫ�����ϧA�P��I�l�x���C
LONG
);
  set_weight(6600);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material","iron");
    set("no_sac",1);
  }
  set("class_only","thief");
  set("value",4380);
  set("volume",1);
  set("weapon_prop/bio", 1);
  set("weapon_prop/wit", -1);
  set("weapon_prop/dodge",5);
  set("weapon_prop/perception",6);
  set("weapon_prop/hit",11);
  set("backstab_bonus",36);
  init_dagger(41);
  setup();
}

void attack(object me,object victim)
{
  if(!me) return;
  if(!victim) return;
  if(me->is_busy()) return;
  if(random(11)) return; // 1/20 �����v�X�{�S��
  if(me->query("evil")<800)
  {
    tell_object(me,"�A��M���@�ѫܷQ���H������A�A���H����G�V�ӶV���c�F�C\n");
    me->add("evil",3+random(10));
  }
  return;
}

