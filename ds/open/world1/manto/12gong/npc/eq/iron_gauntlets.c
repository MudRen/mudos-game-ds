#include <ansi.h>
#include <armor.h>
inherit HANDS;
void create()
{
        set_name(WHT"雅恩格利佩爾"NOR ,({ "iron gauntlets","gauntlets" }) );
        set("long","一雙用白鐵所鍛造而成的手套，重量不輕，但卻能大大減輕使用\n"
                   "雷神之槌所帶來的負荷，故又有一名為「雷神手套」。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(9400);
        set("material", "iron");
        set("unit", "雙" );
        set("value",4300);
        set("armor_type", "hands");
        }
        set("limit_str",50); 
        set("limit_level",40);
        set("armor_prop/armor", 15);
        set("armor_prop/dodge",-15); 
        set("armor_prop/con",4);
        set("armor_prop/str",4);
        set("armor_prop/dex",-3);     
        setup();
}

