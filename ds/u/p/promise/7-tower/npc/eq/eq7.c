#include <armor.h>
#include <ansi.h>
inherit WAIST; 

void create()
{
        set_name(HIW"百妖鏡"NOR, ({ "evil mirror","mirror" }) );
        set_weight(200);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","\n驅趕邪靈之鏡，也可拿來攜帶與驅除迷霧之用。\n"NOR);
                set("unit", "個");
                set("value",1000);
                set("material","gold");
                set("armor_prop/str",-1);
                set("armor_prop/con",2);
                set("armor_prop/bio",1);
                set("armor_prop/armor", 6);
                set("limit_lv",40);
                set("limit_str",50);
                set("limit_con",50); 
                set("limit_int",30);

                set("limit_dex",35);
        }

        setup(); 
}

