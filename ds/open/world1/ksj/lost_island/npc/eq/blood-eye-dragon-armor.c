#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
  set_name(HIR"血眼"WHT"龍甲"NOR ,({ "blood-eye-dragon armor","armor" }) );
  set("long",@LONG
    這是上古惡龍－血眼逆角龍身上的皮甲，相當的堅實而厚重。
上古時代惡龍橫行，雖然古代人將血眼逆角龍埋藏在泥沼之中，但
因為古代缺乏鋒利武器，並無法穿透惡龍皮甲造成致命傷害，導致
惡龍蟄伏未死。而惡龍的皮甲經歷數千年的時光變得更加堅硬難摧
，較任何鋼鐵金屬更為堅硬。
LONG
);
  set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("volume",5);
    set("unit", "件");
    set("value",20000);
  }
  set("limit_lv",40);
  set("armor_prop/armor",40);
  set("armor_prop/con",2);
  set("armor_prop/str",1);
  set("armor_prop/dex",-2);
  set("armor_prop/dodge",-5);
  setup();
}
//int query_autoload() { return 1; }

