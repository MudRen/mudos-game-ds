#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIY"金蠶絲甲"NOR,({"gold-tsan armor","armor"}) );
        set("long",@LONG
由千年金蠶王所吐的金蠶絲所編織而成,刀槍不入,其重量非常輕.
LONG
);
        set_weight(3600); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_dex",20);
                set("limit_con",30);
                set("unit", "件");       
                set("value",4800);          
                set("volume", 5);                       
                set("material", "silk");   
        }
        set("monster_armor_type","armor");
        set("monster_armor_prop/armor",36);       
        set("monster_armor_prop/con",2);
        set("armor_prop/armor",36);
        set("armor_prop/str",1);
        set("armor_prop/con",2);
        
        setup();
}

