#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(HIW"������a"NOR ,({ "silver-snake waist","waist" }) );
  set("long","�@���Q�Ӥت����Ȧ���֡A�{�{�۬��ꪺ�ȥ��C");
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "��");
    set("value",7000);
  }
  set("limit_con",40);
  set("armor_prop/armor",4);
  set("armor_prop/shield",3);
  set("armor_prop/dex",2);
  set("armor_prop/con",1);
  setup();
}
