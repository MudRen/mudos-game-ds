#include <armor.h>
inherit ARMOR;

void create()
{
  set_name("����",({ "bone armor","armor" }) );
  set("long",@LONG
�γ\�h���Y�ꦨ�����ҡA�����a���ͮ�C
LONG);
  set_weight(1500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "stone");
    set("volume",4);
    set("unit", "��");
    set("value",600);
  }
  set("armor_prop/armor",15);
  set("armor_prop/str",1);
  set("armor_prop/int",-1);
  setup();
}
