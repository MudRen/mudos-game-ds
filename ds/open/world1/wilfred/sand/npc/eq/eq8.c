#include <armor.h>
inherit FINGER;
void create()
{
  set_name("�ɴ���" ,({ "jade finger","finger" }) );
  set("long","�@�u�ܴ��q���ɻs�����A�@��a�u����������C");
  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "jade");
    set("volume",1);
    set("unit", "�u");
    set("value",300);
  }
  set("armor_prop/armor",2);
  set("armor_prop/int",1);
  setup();
}