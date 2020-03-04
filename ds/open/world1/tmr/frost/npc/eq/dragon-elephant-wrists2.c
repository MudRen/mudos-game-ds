#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name( CYN "龍象護腕" NOR ,({ "dragon-elephant wrists","wrists" }) );
        set("long",@LONG
龍象為道教四靈之一。原二十八星宿中的東方七宿，因其
組成龍象，位於東方，色青，故稱。亦稱蒼龍。道教嘗以青龍
作護衛神，以壯其威。而這是一個從龍象身上取得的護腕。
LONG
);
        set_weight(5000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("volume",1);
                set("unit", "副" );
                set("value", 5000);
        }
         set("armor_prop/armor", 5);
         set("armor_prop/shield", 5);
         set("armor_prop/str", 2);

        setup();
}

