#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
 set_name(HIW"【"HIG"闇"HIR"之"HIC"帶"HIW"】"NOR, ({ "darkcycle","cycle" }) );
 set_weight(100);
 if( clonep() )
  set_default_object(__FILE__);
 else {
  set("long",""HIW"【"HIG"闇"HIR"之"HIC"帶"HIW"】"NOR"上泛透著"BLK"深黑色"NOR"ㄉ闇光。\n");
  set("unit", "條");
  set("material", "cloth");
  set("no_sell",1);
  set("value",5000);
  set("armor_prop/str",15);
  set("armor_prop/con",15);
  set("armor_prop/int",8);
  set("armor_prop/dex",8);
  set("armor_prop/damage",150);
  set("armor_prop/armor",150);
  set("armor_prop/dodge",150);
}
        setup();  
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }









