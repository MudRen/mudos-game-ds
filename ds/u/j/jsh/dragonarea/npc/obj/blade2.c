#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIW"���M"NOR, ({ "long blade", "blade" }));
        set("long", "�@��������M�C\n");
        set_weight(8000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("volume",3);
                set("material", "crimsonsteel");
                set("limit_skill",20);
                set("limit_str",20);
                      set("value",1200);
                set("limit_lv", 5);
               }
        set("weapon_prop/armor", 8); 
        set("weapon/prop/dodge",-2);       
        set("wield_msg","$N��$n���b��W�C\n");
        set("unwield_msg", "$N��$n��U�C\n");

        init_blade(30);
        setup();
}

