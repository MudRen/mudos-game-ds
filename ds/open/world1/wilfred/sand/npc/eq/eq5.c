#include <armor.h>
inherit CLOTH;
void create()
{
  set_name("�M�A" ,({ "kimono","cloth" }) );
  set("long","�զ�����s�����e�j�T�l�A�E�ݤ��U����x�A�A�����M�A���������j��C");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "��");
    set("value",800);
  }
  set("armor_prop/armor",5);
  setup();
}