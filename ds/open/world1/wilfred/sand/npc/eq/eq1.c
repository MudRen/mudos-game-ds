#include <armor.h>
inherit WAIST;
void create()
{
  set_name("�y��" ,({ "woman waist","waist" }) );
  set("long","�o�O���k�諸�y�a�A�q�`�]�����ƨ��q���\\��C");
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("volume",1);
    set("unit", "��");
    set("value",300);
  }
  set("armor_prop/armor",3);
  setup();
}