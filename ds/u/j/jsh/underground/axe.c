#include <weapon.h> 
#include <ansi.h>
inherit AXE;
void create()
{
        set_name(HIW"鋸齒闊斧"NOR, ({ "tooth big-axe" , "axe" }) );
        set_weight(1200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",10);
                set("unit", "把");
                set("long", "一把鋸齒狀的闊斧, 殺傷力比一般的斧頭強。\n");
                set("value", 2000);
        }
        init_axe(35);
        setup();
}

