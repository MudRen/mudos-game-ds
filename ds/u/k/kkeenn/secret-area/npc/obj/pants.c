#include <armor.h>
#include <ansi.h>
inherit PANTS;
void create()
{
        set_name(GRN"氫原褲"NOR, ({ "H2 pants","pants" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一條由氫原素組成的氣體褲子。\n");
                set("unit", "條");
                set("no_sell",1);
                set("no_sac",1);
                set("value",1100);          
                set("wear_msg", "當$N把$n穿上的時候, $N的動作好像沒穿褲子一樣\n");
           }
        set("armor_prop/dodge",5);
        set("armor_prop/armor",4);
        setup();
}

