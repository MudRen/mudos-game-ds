#include <armor.h>
inherit PANTS;

void create()
{
        set_name("青色長褲" ,({ "green pants","pants" }) );
        set("long",@LONG
這是一件青絹布長編織而成的長褲，質料雖不高級但縫工良好。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "條");
                set("value",600);
        }
        set("armor_prop/armor",4);
        setup();
}

