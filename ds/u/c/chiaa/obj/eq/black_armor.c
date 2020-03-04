//u/c/chiaa/obj/eq/black_armor.c
#include <armor.h>
#include <ansi.h>
inherit ARMOR;
                        
void create()
{
     set_name(BLU"黑蠶"CYN"戰甲"NOR,({"black armor","armor"}) );
     set("long","以珍貴黑蠶絲混合鋼絲打造而成的盔甲,重量較一般盔甲來的輕。\n");
 
   if( clonep() )
            set_default_object(__FILE__);
        else {
       
        set_weight(10000);
        set("unit", "套");
        set("value",5000);
        set("material","steel silk");  //材質 鋼 蠶絲
        set("armor_prop/armor",50 );  //增加防禦力50
        }
        setup();
}
