#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
        set_name(HIB"鬼甲"NOR,({"ghost plate","plate"}) );
        set("long",@LONG
由半獸人皮以及地精皮所混合製成的硬皮盔甲雖然臭了些，但它所提
供的防護力卻是無庸置疑的。
LONG
);
        set_weight(8000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_str",10);
                set("limit_con",10);
                set("unit", "件");       
                set("value",1000);          
                set("volume", 4);                       
                set("material", "skin");   
        }
        set("armor_prop/armor",25);       
        set("armor_prop/con",1);
        setup();
}


