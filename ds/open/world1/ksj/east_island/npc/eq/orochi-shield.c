#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(GRN"�K�["HBK"���"NOR,({"orochi shield","shield"}));
  set("long", @LONG
�K�[�j�D���B�Y�W���@������s�����޵P�A�����Ʀӱa���ȥ��A��
���K�ٰ�w�A�����q�۷��C
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "��");
    set("volume",3);
    set("value",7000);
    set("material","fur");
  }
  set("limit_lv",40);
  set("armor_prop/armor",27);
  set("armor_prop/shield",19);
  set("armor_prop/dodge",8);
  set("armor_prop/str",2);
  set("armor_prop/con",1);
  setup();
}
