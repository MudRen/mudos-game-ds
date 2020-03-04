#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
 set_name(HIR"�u"HIW"�E"NOR"�K�["HIY"���"NOR ,({ "orochi plate","plate" }));
  set("long",@LONG
�K���j�D����ֻs�����֥ҡA�����M�j���J�A�󦳤K���j�D�j�j����
�O�C
LONG);
  set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",4);
    set("unit", "��");
    set("value",15000);
  }
  set("limit_con",50);
  set("limit_lv",40);
  set("armor_prop/armor",60);
  set("armor_prop/shield",40);
  set("armor_prop/bio",-1);
  set("armor_prop/bar",-1);
  set("armor_prop/wit",1);
  set("armor_prop/dex",-1);
  set("armor_prop/dodge",-5);
  setup();
}

int query_autoload() { return 1; }
