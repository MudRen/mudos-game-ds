#include <armor.h>
inherit PANTS;

void create()
{
        set_name("Arai�ֿ�",({ "arai pants","pants" }) );
        set("long",@LONG
�o�O�@��饻�i�f��Arai�ֿǡC
LONG
);
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "skin");
                set("unit", "��");
                set("limit_level",30);
        }
        set("armor_prop/armor",17);
        setup();
        set("value",9000);
        set("volume",4);
}
int query_autoload() { return 1; }
