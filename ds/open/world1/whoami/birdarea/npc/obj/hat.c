#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name(MAG"埜狐面罩"NOR, ({ "fox mask", "mask"  }) ); 
         set("long","這是用殺人狐九尾身上的皮所製成的面罩，雖然這只是牠的皮，\n"
                   "不過還是感到有微微的殺意。\n");
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面" ); 
                set("material","fur");
        }
                set("value",16000);
                set("armor_prop/armor",  12);
                set("armor_prop/con", 2);
                set("armor_prop/str", 3); 
                set("armor_prop/bar", 1);
                set("armor_prop/tec", 1);
                set("armor_prop/wit", -2);
                set("limit_level",40);
        setup();
}

