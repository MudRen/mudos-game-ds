#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
        set_name("風隱戒",({"storm ring","ring"}) );
        set("long",@LONG
一枚帶著藍色湖光的戒指，摸起來有股清涼的感覺。
LONG
);
        set_weight(300); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");       
                set("value",1200);          
                set("volume", 2);                       
                set("material", "stone");   
        }
        set("limit_con",20);
        set("limit_int",30);
        set("armor_prop/armor",3);       
        set("armor_prop/int",3);
        setup();
}

