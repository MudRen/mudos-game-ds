#include <armor.h>
inherit BOOTS;
void create()
{
        set_name("Arai�ɨ��u",({"arai boots","boots"}) );
        set("long",@LONG
�o�@���饻��˶i�f��Arai�ɨ��u�A�۷��p���C
LONG
);
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "skin");
                set("unit", "��");
                set("limit_level",30);
        }
        set("value",3450);
        set("armor_prop/armor",12);
        setup();
        set("volume", 4);
}
int query_autoload() { return 1; }
