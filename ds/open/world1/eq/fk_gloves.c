#include <ansi.h>
#include <armor.h>
inherit HANDS;

void create()
{
        set_name("炎殺手套",({"flame kill gloves","gloves"}) );
        set("long",@LONG
紅色的手套，上面還帶有倒鉤，使用時可得小心。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",20);
                set("unit", "雙");       
                set("value",1200);          
                set("volume", 4);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/str",1);
        set("armor_prop/damage",2);
        set("armor_prop/bio",-1);
        set("armor_prop/wit",-1);
        setup();
}


