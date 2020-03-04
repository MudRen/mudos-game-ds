#include <ansi.h>  
#include <armor.h>
inherit SHIELD; 
void create()
{
        set_name(HIW"水鏡之盾"NOR,({ "water-mirror shield","shield" }) );
        set("long","這是用白水晶細細磨成的小盾，表面光滑而閃亮，裡面則刻滿花紋 \n"                   "對於魔法類的攻擊有絕佳的抵抗力。\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","gold");
                set("unit", "件" );
                set("no_sell",1); 
                set("value",30000);
                set("armor_prop/armor", 10);
                set("armor_prop/shield",45);
        }
        setup();
} 

