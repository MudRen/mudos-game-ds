#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIW"��q�y�a"HIR"(S)"NOR ,({ "lion waist","waist" }) );
        set("long",@LONG
���K���s�����y�a�A�y�a�Y�O�@�ӻȻs�����Y�C
LONG);
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "steel");
    set("volume",3);
    set("unit", "��");
    set("value",7000);
  }
  set("armor_prop/armor",8);
  setup();
}

int query_autoload() { return 1; }
