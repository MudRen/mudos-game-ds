#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("���M", ({ "steel blade","blade" }) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "  �@��ο��`�y���M�l�A�Q�����­��A���L�Ψӫo�o������C\n");
                set("material", "steel");
                set("value",7000);
         }
    init_blade(20);
    setup();
}


