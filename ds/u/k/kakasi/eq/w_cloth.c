#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
  set_name(HIG"�ꤧ��"NOR ,({ "mimi cloth","cloth" }) );
  set("long","�a����������A�C");

  set_weight(1900);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",2);
    set("unit", "��");
    set("value",1200);
  }
  set("armor_prop/armor",21);
  setup();
}
