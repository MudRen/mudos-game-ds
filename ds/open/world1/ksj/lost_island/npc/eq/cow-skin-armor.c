#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("����֥�",({ "cow-skin armor","armor" }) );
  set("long",@LONG
�o�O����ֻs�����֥ҡA�R���y��۷��¯ٷP�A�ӥB���ְ��@��
�A�O�󤣿����֥ҡC
LONG
);
  set_weight(4000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",4);
    set("unit", "��");
    set("value",7500);
  }
  set("limit_con",25);
  set("armor_prop/armor",27);
  set("armor_prop/con",2);
  set("armor_prop/dex",-1);
  set("armor_prop/damage",4);
  setup();
}
