#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIY"佛光"HIW"袈裟"NOR ,({ "buddha cloth","cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
 set("long",@LONG
這是傳說中釋迦摩尼穿的袈裟,袈裟看起來金光閃閃,穿起來你的法力會加高許多.
LONG
     );
        set("unit", "件");
        set("value",0);
        set("material", "steel");
        set("limit_con",30);
        set("limit_lv",20);
}
        set("armor_prop/armor",14);
        set("armor_prop/con",2);
        set("armor_prop/wit",1);      
       
        
        setup();
}


