#include <armor.h>
inherit HEAD;
void create()
{
  set_name("���U" ,({ "student hat","hat" }) );
  set("long","�ǪL���l�̱`�����U�l�C");
  set_weight(300);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "��");
    set("value",200);
  }
  set("armor_prop/armor",2);
  setup();
}