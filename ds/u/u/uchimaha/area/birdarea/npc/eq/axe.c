#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
        set_name("����K��", ({ "wood axe","axe" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�`�K��O�M���Ψӥ�쪺�C\n");
                set("material", "iron");
                set("value",1000);
                set("limit_skill",10);
                set("limit_str",20);
        }
    set("weapon_prop/con",1);
    set("weapon_prop/dex",-1);
    set("weapon_prop/parry",3);
    set("weapon_prop/dodge",-3);
    init_axe(20);
    setup();
}

