#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
          set_name(MAG "沖天冠" NOR,({ "chung-sky-guan","guan"}) );
        set("long","由夜光翡翠打造而成,在沖天冠的末端,還有一個小珠子\n");
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "jade");
                set("unit","頂");
        }
        set("value",3500);
        set("limit_lv",25);
        set("armor_prop/armor",12);
        set("armor_prop/str",1);
        set("armor_prop/con",1);
        set("armor_prop/int",1); 
        setup();
        set("volume",3);
}

