#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
  set_name(HIW"冰霜皮衣"NOR ,({ "frost-troll cloth","cloth" }) );
  set("long",@LONG
這是由北方大森林的冰霜巨魔取得的皮衣，銀白的毛色，尤如真正
的冰霜一樣漂亮。
LONG
);
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "件");
    set("value", 20000);
    set("material", "fur");
  }
    set("limit_lv",40);
    set("armor_prop/str",1);
    set("armor_prop/int",2);
    set("armor_prop/dex",2);
    set("armor_prop/shield",10);
    set("armor_prop/armor", 20);

  setup();
}

