#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(HIY "金杈" NOR,({ "gold zar","zar" }) );
        set("long","金杈由純黃金打造而成的頭飾，看來價值非凡。\n");
        set_weight(600);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "gold");
                set("unit","支");
        }
        set("value",1000);
        
        set("armor_prop/armor",4);
        set("armor_prop/int",1);
           setup();
        set("volume",3);
}

