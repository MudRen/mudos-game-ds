#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("不和脛甲",({"bo-ho leggings","leggings"}) );
        set("long",@LONG
奇形怪狀的脛甲，裝備起來相當麻煩。
LONG
);
        set_weight(500); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_dex",20);
                set("unit", "雙");       
                set("value",1070);          
                set("volume", 4);                       
                set("material", "steel");   
        }
        set("armor_prop/armor",4);       
        set("armor_prop/dex",1);
        set("armor_prop/int",-1);
        setup();
}

