#include <ansi.h>
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name(HIC"天蹤"HIM"幻"BLU"布"NOR ,({ "shadow-sky shoes","shoes" }) );
        set("long", @LONG
一雙由亮銀絲布包覆的娃娃鞋，是流行教主特有的行頭之一。

感激 ayumi 對DS網站的貢獻。 -Tmr 2007/04/08
LONG
);
  set_weight(200);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("unit", "雙");
    set("volume",1);
    set("no_drop",1);
    set("no_give",1);
    set("no_get",1);
    set("no_put",1);
    set("no_sell",1);
  }
  set("armor_prop/armor", 5);
  set("armor_prop/shield",5);
  set("armor_prop/bar",1);
  set("armor_prop/show_damage",1);
  setup();
}

int query_autoload() { return 1; }



