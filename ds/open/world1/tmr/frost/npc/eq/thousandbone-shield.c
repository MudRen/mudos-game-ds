#include <ansi.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name("千骨盾",({"thousand-bone shield","shield"}) );
        set("long",@LONG
這是一面由數十塊頭骨拼湊而成的骨盾，令人覺得怪異恐怖。
LONG
);
        set_weight(3000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",20);
                set("limit_con",20);
                set("limit_dex",20);
                set("unit", "面");       
                set("value",2500);          
                set("volume", 4);                       
                set("material", "mica");   
        }
        set("armor_prop/armor",20);     
        set("armor_prop/shield",10);   
        set("armor_prop/con",1);   
        setup();
}

