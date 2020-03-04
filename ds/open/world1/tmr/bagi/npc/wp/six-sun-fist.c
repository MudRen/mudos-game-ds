#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(HIY"禁地六陽爪"NOR,({"six-sun-fist","fist"}) );
        set("long",@long
相傳此爪為八極門開山祖師-吳鍾，守於八極禁地，所使用之武器。
long
);
        set_weight(8000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","對");
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

