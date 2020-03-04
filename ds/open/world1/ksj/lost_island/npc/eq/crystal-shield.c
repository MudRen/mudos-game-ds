#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
  set_name(HIW"水晶盾牌"NOR,({"crystal shield","shield"}));
  set("long", @LONG
堅硬的天然白水晶製成的盾牌，除了本身價值不菲，更有不錯的防護
力，是古代高階魔法師所製作的珍貴防具。
LONG);
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "面");
    set("volume",3);
    set("value",80000);
    set("material","stone");
  }
  set("armor_prop/armor",20);
  set("armor_prop/shield",25);
  set("armor_prop/int",1);
  setup();
}
