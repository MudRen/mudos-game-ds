#include <armor.h>
inherit SHIELD;
void create()
{
        set_name("Arai護肘",({"arai elbow cap","cap","elbow"}) );
        set("long",@LONG
這是一副日本進口的Arai護肘，可以保護使用者的手肘不至於擦傷。
LONG);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","wood");
                set("unit", "副");
                set("limit_level",30);
             }
        set("armor_prop/armor",14);
        setup();
        set("value",1600);
        set("volume", 4);
}
int query_autoload() { return 1; }
