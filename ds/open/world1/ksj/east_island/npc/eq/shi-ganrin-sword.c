#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
  set_name(HIG"���l"HIY"�[�L�C"NOR, ({ "shi-ganrin sword","sword" }) );
  set("long",@long
�C�b�ĥίS����y�覡�s�y�A�X�G���|�l�a�A�C�`�h�O�λ��K�ȥ�O
�X���R����R��L�ϮסC
long);      
  set_weight(2850);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("material", "blacksteel");
    set("value",10500);
    set("volume",4);
    set("rigidity",1100);
    set("limit_skill",50);
    set("limit_lv",30);
    set("weapon_prop/int",1);
  }
  init_sword(58);
  set("wield_msg","$N�ޥX�y����$n�A�O�H���ѱo�g�Ĩ���R�C\n"NOR);
  set("unwield_msg","$N���ӼC��A�����a�N$n���^�C�T���C\n");
  setup();
}
