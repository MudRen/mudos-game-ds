#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"【"HIG"闇"HIR"之"HIC"衣"HIW"】"NOR ,({ "darkcloth","cloth" }) );
        set("long",""HIW"【"HIG"闇"HIR"之"HIC"衣"HIW"】"NOR"上泛透著"BLK"深黑色"NOR"ㄉ闇光。
\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "件" );
        set("no_sell",1);
        set("value",150);
        }
          set("armor_prop/armor",300);
          set("armor_prop/parry",200);
          set("armor_prop/dodge",200);
          set("armor_prop/str",12);
          set("armor_prop/con",12);
          set("armor_prop/int",7);
          set("armor_prop/dex",7);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
 int query_autoload() { return 1; }











