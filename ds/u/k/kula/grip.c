#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
  set_name( MAG "����v��" NOR ,({ "hair grip","grip" }) );
  set("long","�i�ԥΨӸj�Y�v���v���C");
  set_weight(30);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",1);
    set("unit", "��");
    set("value",1);
  }
  set("armor_prop/armor", 1);
  set("armor_prop/int", 2);
  setup();
}

int query_autoload() { return 1; }

