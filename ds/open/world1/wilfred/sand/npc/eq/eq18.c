#include <ansi.h>
#include <armor.h>
inherit FINGER;
void create()
{
  set_name(WHT"�ȧ�"NOR ,({ "silver ring","ring" }) );
  set("long","�o�O�@���Ȼs���٫��A�{�{�o���A�O�H�R������C");
  set_weight(500);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",1);
    set("unit", "�u");
    set("value",1000);
  }
  set("armor_prop/armor",3);
  setup();
}

int query_autoload() { return 1; }
