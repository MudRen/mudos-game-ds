#include <ansi.h>
#include <armor.h>
inherit PANTS;
void create()
{
  set_name(HIR"��ù��M��"NOR ,({ "shu lo pants","pants" }) );
  set("long","�|�j������@���P�D�ۨϥΪ�����C");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cold");
    set("volume",2);
    set("unit", "��");
    set("value",2100);
  }
  set("armor_prop/armor",10);
  set("armor_prop/con",1);
  setup();
}





