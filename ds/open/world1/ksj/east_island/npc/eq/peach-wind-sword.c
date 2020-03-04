#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIM"��"HIC"��"HIM"�b"HIC"�C"NOR, ({ "peach-wind sword","sword" }) );
  set("long",@long
�C�b�e�{�}�G�����Ŧ�A�����O����谵���A�C�`�P�C�T�h�O���s
���A�W���J�観��Ӫ���L�K���ϡA�ڻ����C�O��ᯫ�Ұt�a�C
long);      
  set_weight(1850);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value",8000);
    set("volume",4);
    set("limit_skill",30);
    set("limit_lv",35);
  }
  set("weapon_prop/str",-2);
  init_sword(52);
  set("wield_msg","$N�ޥX�y����$n�A���ꪺ�C���ϤH���g�C\n"NOR);
  set("unwield_msg","$N���ӼC��A�����a�N$n���^�C�T���C\n");
  setup();
}

void attack(object me, object victim)
{
  int be_busy;
  ::attack();
  if(!me) return;
  if(!victim) return;

  if(me->query_sou() > 2 && !random(7))
  {
    message_vision(HIM"\n�筷�b�C���C�~�ۤƦ��@�������A�b$n"HIM"���|�P���୸�R�C\n"NOR,me,victim);
    be_busy=me->query_sou();
    if (be_busy > 5) be_busy=5;
    message_vision("$N"HIR"�إ��b�����J�g�ڤ����I�I\n"NOR,victim);
    victim->add_busy(random(be_busy));
  }
  return;
}
