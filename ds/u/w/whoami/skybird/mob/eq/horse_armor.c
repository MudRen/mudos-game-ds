#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(CYN"精鋼重甲"NOR,({"huge armor","armor"}) );
        set("long",@LONG
這是一件製作難度極高的鍊甲，為數條精練鋼互相交錯編織而成。 
這件是為戰馬而作的•
LONG);
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "件");
        }
        set("value",1800);
        set("limit_lv",25); 
        set("limit_race","野獸");
        set("armor_prop/armor",39);
        set("armor_prop/shield",13); 
        set("armor_prop/con",2);
        set("armor_prop/dex",-2);
        setup();
}

