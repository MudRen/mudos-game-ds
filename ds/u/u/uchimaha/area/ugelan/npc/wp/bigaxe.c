#include <weapon.h>
inherit AXE;
void create()
{
        set_name("����", ({ "big axe","axe" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�⥨��O���������M�h���зǰt��, ���O�ˮ`�O�o�]���p�C\n");
                set("material", "silver");
                set("limit_str",24);
             }
    set("weapon_prop/str",2);
    init_axe(60,TWO_HANDED);
    setup();
}
