#include <ansi.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(CYN"塵風脛"NOR,({"wind leggings","leggings"}) );
        set("long",@LONG
這是雲風聖道的護腿，看來來歷不小...
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
                set("material", "blacksteel");   
        }
        set("armor_prop/armor",5);       
        set("armor_prop/dex",1);
        set("armor_prop/int",1);
        setup();
}

