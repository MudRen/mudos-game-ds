#include <armor.h>
#include <armor.h>
inherit PANTS;
void create()
{
        set_name("AD��" ,({ "ad.pants" }) );
        set("long","���l���M�ݤ��J�ǡC\n");
        set_weight(100);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("value" ,50);
                set("material","linen");
        }
        set("armor_prop/armor", 300);
        set("armor_prop/shield", 300);
        setup();
}
        int query_autoload() { return 1; }

