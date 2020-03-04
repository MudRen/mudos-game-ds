#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
    set_name(HIR"真"HIW"•"NOR"八歧"HBK"鱗盾"NOR,({"orochi shield","shield"}));
  set("long", @LONG
八歧大蛇的額頭上的一片鱗片製成的盾牌，表面光滑而帶有銀光，比
鋼鐵還堅硬，但重量相當輕。
LONG);
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else 
  {
    set("unit", "面");
    set("volume",3);
    set("value",7000);
    set("material","fur");
  }
  set("limit_lv",40);
  set("armor_prop/armor",27);
  set("armor_prop/shield",19);
  setup();
}

int query_autoload() { return 1; }
