#include <ansi.h>
#include <armor.h>
inherit WRISTS;
void create()
{
  set_name(WHT"���N"NOR ,({ "silver wrists","wrists" }) );
  set("long","�o�O�@�ӻȻs�����N�A�{�{�o���A�O�H�R������C");
  set_weight(800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "silver");
    set("volume",1);
    set("unit", "��");
    set("value",1000);
  }
  set("armor_prop/armor",3);
  setup();
}

int query_autoload() { return 1; }
