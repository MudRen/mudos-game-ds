#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(HIY"�T�a������"NOR,({"six-sun-fist","fist"}) );
        set("long",@long
�۶Ǧ������K�����}�s���v-�d��A�u��K���T�a�A�ҨϥΤ��Z���C
long
);
        set_weight(8000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",5000);
        set("material","gold");
        set("volume",1);
        set("limit_str",50);
        set("limit_level",25);
        }
        set("weapon_prop/str",1);
        set("weapon_prop/dex",-1);
        set("weapon_prop/hit",10);
        set("beast_weapon_prop/damage",50);
        set("beast_weapon_prop/hit",20);
        init_fist(65);
        setup();
}

