#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
        set_name("面膜" ,({ "face-dermo" , "dermo" }) );
        set("long","這是用來保養皮膚的面膜，有強烈的黏性。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "peel");
        set("unit", "頂" );
                set("value",10);
        }
        set("armor_prop/armor", 1);
        set("armor_prop/id",({"dermo people"}));
        set("armor_prop/name",({"臉戴面膜的怪人"}));
        set("armor_prop/short",({"臉戴面膜的怪人"}));
set("armor_prop/long",({"一個臉戴面膜的人，你心裡不禁懷疑，是不是一個神經病。\n"}));
        setup();
} 
