#include <weapon.h>
inherit BLADE;
void create()
{
        set_name( "���M" , ({ "steel blade","blade" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@��w�w�����M, ���G�ܭ����ˤl....�C\n");
                set("material", "steel");
                set("limit_str",10);
        }
    set("weapon_prop/dex",-1);
    init_blade(17);
    setup();
}


