#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name(  "鳥象腰帶" ,({ "bird-elephant belt","belt" }) );
        set("long",@LONG
鳥象為道教四靈之一，二十八星宿中的南方七宿，而這
是一條從鳥象身上取得的腰帶，質地奇異，色發紅光。
LONG
);
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("volume",1);
                set("unit", "條" );
                set("value", 5000);
        }
         set("armor_prop/armor", 5);
         set("armor_prop/shield", 5);
         set("armor_prop/int", 1);

        setup();
}

