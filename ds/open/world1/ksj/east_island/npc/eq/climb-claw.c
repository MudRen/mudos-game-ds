#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create()
{
  set_name("��ҹ_", ({ "climb claw","claw" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_skill",20);
    set("unit", "��");
    set("long", "�Υ|���K�_�s�b�K���W�A�ⴤ���K���i�H�����ĤH�A�]�i�H�Ψ��k��C\n");
    set("value",1000);
    set("volume",3);
    set("material","steel");
  }
  init_fist(15,TWO_HANDED);
  setup();
}
