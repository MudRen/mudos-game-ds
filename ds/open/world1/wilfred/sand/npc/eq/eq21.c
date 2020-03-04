#include <ansi.h>
#include <armor.h>
inherit WAIST;

void create()
{
  set_name(YEL"�d�~�sŽ"NOR ,({ "dragon beard","beard" }) );
  set("long","�@���Q�Ӥت����sŽ�A��@�J���A�U���ǳ\\�զ�H���C");
  set_weight(400);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",3);
    set("unit", "��");
    set("value",3800);
  }
  set("limit_int",10);
  set("armor_prop/armor",4);
  set("armor_prop/dex",3);
  set("armor_prop/dodge",5); //5->3 by ksj
  set("beast_armor_prop/armor",4);
  set("beast_armor_prop/dex",3);
  set("beast_armor_prop/dodge",5); //5->10 by ksj
  setup();
}
