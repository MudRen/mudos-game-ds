#include <ansi.h>
#include <armor.h>
inherit ANKLE;

void create()
{
  set_name(HIY"�b��}��"NOR ,({ "run-moon ankle","ankle" }) );
  set("long","�o�O�@����a�ǲ����}��A��b�}��W�A�n���ٺ��Ӯ𪺡C");
  set_weight(1800);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "��");
    set("value",0);
  }
  set("armor_prop/armor",5);
  set("armor_prop/shield",5);
  set("armor_prop/str",3);
  set("armor_prop/con",3);
  set("armor_prop/int",3);
  set("armor_prop/dex",3);
  setup();
}

