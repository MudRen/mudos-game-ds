#include <ansi.h>
#include <armor.h>
inherit SURCOAT;

void create()
{
        set_name("八歧披風",({"ba-chi cloak","cloak"}) );
        set("long",@LONG
黑天蠶絲編織的披風，堅韌的防護力，是不可多得的極品。
LONG
);
        set_weight(1000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_con",15);
                set("unit", "頂");       
                set("value",900);          
                set("volume", 3);                       
                set("material", "silk");   
        }
        set("armor_prop/armor",15);       
        set("armor_prop/str",2);
        setup();
}


