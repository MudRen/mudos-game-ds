#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIR"���@"HIW"�n"HIC"�C"NOR, ({ "best sword","sword"} ) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��");
        set("material","diamond");
                set("long", "�o�O�@���|�@�L�����C�C\n");
                set("value", 1000);
}
    set("weapon_prop/bar",11);
        init_sword(100);
        setup();
}

