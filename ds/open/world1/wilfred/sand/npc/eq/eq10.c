#include <armor.h>
inherit LEGGING;
void create()
{
  set_name("�j�L" ,({ "leggings" }) );
  set("long","����̤@��樫���򪺪Z�L�H�h���򥻸˧��A���ۨǳ\\�����m�O�C");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "��");
    set("value",700);
  }
  set("armor_prop/armor",6);
  setup();
}