#include <armor.h>
inherit HANDS;
void create()
{
  set_name("���x" ,({ "bear gloves","gloves" }) );
  set("long","��������x�A���ݳo���x���j�p�A�N���D�Q������i�O�|���H���C");
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "skin");
    set("volume",2);
    set("unit", "��");
    set("value",2000);
  }
  set("armor_prop/armor",7);
  set("beast_armor_prop/armor",7);
  set("limit_con",12);
  setup();
}
