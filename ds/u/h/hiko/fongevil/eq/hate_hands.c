#include <ansi.h>
#include <armor.h>
inherit WRISTS;

void create()
{
        set_name("怨腕",({"hate hands","hands"}) );
        set("long",@LONG
由於主人是含恨而死，因此怨氣極重的護腕。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_int",15);
        

                set("unit", "對");       
                set("value",3200);          
                set("volume", 3);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",2);       
        set("armor_prop/con",1); 
        setup();
}

