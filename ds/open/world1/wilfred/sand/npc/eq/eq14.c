#include <armor.h>
inherit NECK;
void create()
{
  set_name("�f���@��" ,({ "cypress necklace","necklace" }) );
  set("long","�լf�s�����@�šA���G�����O�[���󦹡C");
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "wood");
    set("volume",2);
    set("unit", "��");
    set("value",1400);
  }
  set("armor_prop/armor",5);
  set("armor_prop/int",2);
  set("beast_armor_prop/armor",5);
  set("beast_armor_prop/int",2);
  setup();
}
