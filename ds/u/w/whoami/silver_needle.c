#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("�Ȱw",({"silver needle","needle"}) );
        set_weight(150);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("unit", "��");
                set("base_volume",1);
                set("base_weight",150);
                set("material", "iron");
        set("long",@LONG
�@�ڻȰw�E
LONG);
        }
        init_throwing(1);
        setup();
        set("value",150);
        set("volume", 1);
        set_amount(1);
}

