#include <ansi.h>
#include <armor.h>
inherit WRISTS;
void create()
{
        set_name(HIW"清玉腕"NOR,({"white wrist","wrist"}) );
        set("long",@LONG
這是由巧匠所製成的護腕，看來相當不錯.
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",20);
                set("unit", "雙");
                set("light",1);       
                set("value",1070);          
                set("volume", 4);                       
                set("material", "jade");   
        }
        set("armor_prop/armor",6);       
        set("armor_prop/dex",2);
        setup();
}

