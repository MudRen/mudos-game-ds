#include <ansi.h>
#include <armor.h>
inherit LEGGING;
void create()
{
        set_name(MAG"邪桫脛"NOR,({"baal leggings","leggings"}) );
        set("long",@LONG
這雙脛甲頗為奇異, 在楊光下不會反射光芒, 但在黑暗
處卻會微微的發出紫光....
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_dex",20);
                set("unit", "雙");
                set("light",1);       
                set("value",1070);          
                set("volume", 4);                       
                set("material", "blacksteel");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/dex",1);
        set("armor_prop/int",-3);
        setup();
}

