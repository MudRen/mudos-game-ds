#include <armor.h>
inherit PANTS;
#include <ansi.h>
void create()
{
  set_name(HIM"��"HIC"��"HIW"�e��"NOR ,({ "Dreamcast pants","pants" }) );
  set("long","�o�ODreamcast�M�ݪ��Ǥl�A��_�ӵΪA�S�w��");
  set_weight(3000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",1200);
  }
  set("armor_prop/armor",100);
  setup();
}


