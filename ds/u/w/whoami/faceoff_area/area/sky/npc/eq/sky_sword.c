#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIC "�ѫC�C" NOR,({"sky sword","sword"}) );
        set("long",
        "�@��W�n�C�����y���C�C\n"
        );
        set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
                set("limit_str",20);
                set("value",1000);
                set("volume",2);
                set("limit_skill",20);
                set("material","steel");
         }
        set("weapon_prop/str",2);
        set("weapon_prop/con",1);
        init_sword(23);
        setup();        
}

