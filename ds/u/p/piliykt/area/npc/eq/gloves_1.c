#include <armor.h>
inherit HANDS;
void create()
{
  set_name("��]" ,({ "buddha pearl","pearl" }) );
  set("long","�M�|������],�W�g�ۧڦ�O�d. ");
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "skin");
    set("volume",2);
    set("unit", "�u");
    set("value",10);
  }
  set("armor_prop/armor",6);
  set("armor_prop/con",1);
  set("armor_prop/bio",-1);

  setup();
}

