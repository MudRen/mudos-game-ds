#include <armor.h>

inherit BOOTS;
#include <ansi.h>
void create()
{
        set_name(HIW"【"HIG"闇"HIR"之"HIC"靴"HIW"】"NOR,({"darkboots","boots"}) );
        set("long",""HIW"【"HIG"闇"HIR"之"HIC"靴"HIW"】"NOR"上泛透著"BLK"深黑色"NOR"ㄉ闇光。\n");
     set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","雙");
        set("no_sell",1);
        set("value",5000);           
        set("material","boots"); 
        set("armor_prop/con", 10) ;     
        set("armor_prop/str", 10) ;     
        set("armor_prop/int",5);
        set("armor_prop/dex",10);
        set("armor_prop/armor",100);
        set("armor_prop/parry",100);
        set("armor_prop/dodge",300);
        }
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
} 
 int query_autoload() { return 1; }












