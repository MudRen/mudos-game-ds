#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIC"淡月疏星"NOR, ({ "moon-star cloth", "cloth"  }) );
        set("long","這是一件以不知名稠緞編織而成的女性衣裳，只見其光彩奪目，\n"
                   "瑰麗精奇，不似是人間之物。\n");
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件" );
                set("value", 8000);
                set("material", "cloth");
        }
        set("armor_prop/armor",  15);
        set("armor_prop/shield",  15);
        set("armor_prop/bio", 1);
        set("armor_prop/wit", -1);
        set("female_only",1);
        setup();
}

