#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIW"【"HIG"闇"HIR"之"HIC"戰甲"HIW"】"NOR,({ "darkarmor","armor" }) );
        set("long",""HIW"【"HIG"闇"HIR"之"HIC"戰甲"HIW"】"NOR"上泛透著"BLK"深黑色"NOR"ㄉ闇光。\n");
         set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "armor");
        set("unit", "件" );
        set("no_sell",1);
        set("value",3000);
        }
set("armor_prop/armor",300);
set("armor_prop/dodge",100);
set("armor_prop/dex",6);
set("armor_prop/int",6);
set("armor_prop/con",10);
set("armor_prop/str",10);
        setup();
 {
  if(!wizardp(this_player())) destruct(this_object());
}
}
 int query_autoload() { return 1; }










