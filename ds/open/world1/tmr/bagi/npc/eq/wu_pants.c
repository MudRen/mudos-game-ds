#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
        set_name(HIY "寒日獸毛褲" NOR ,({ "freeze-sun pants","pants" }) );
        set("long",@LONG
這是一件由八極禁地的守護獸「寒日」的數串毛髮編織而成的毛褲。    
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "條");
                set("value",1200);
        }
        set("armor_prop/armor",8);
        set("armor_prop/int",1);
        set("armor_prop/con",1);
        setup();
}
