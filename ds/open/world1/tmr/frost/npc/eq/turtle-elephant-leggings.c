#include <armor.h>
#include <ansi.h>
inherit LEGGING;

void create()
{
        set_name( "龜象護膝"  ,({ "turtle-elephant leggings","leggings" }) );
        set("long",@LONG
龜象為道教四靈之一，二十八星宿中的北方七宿，而這
是一個從龜象身上取得的護膝，質地堅硬，色發青光。
LONG
);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("volume",1);
                set("unit", "個" );
                set("value", 5000);
        }
         set("armor_prop/armor", 5);
         set("armor_prop/shield", 5);
         set("armor_prop/dex", 1);

        setup();
}

