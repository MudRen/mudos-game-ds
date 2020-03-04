#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIC"魂"HIY"元"HIR"魔劍"NOR, ({ "soul sword","sword" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是一把隱藏在影爪魂身體內的魔劍。表面血紅帶有光澤，殺氣騰騰。\n");
                set("volume",10);
                set("value", 20000);
                set("material","iron");
  }
                set("limit_lv",40);
                set("limit_skill", 80);
                set("weapon_prop/str",1);
                set("weapon_prop/con",3);
                set("weapon_prop/int",3);
                set("weapon_prop/wit",1);
                set("weapon_prop/hit",70); 
        set("wield_msg", "$N握住$n時，似乎能感覺到有一股強大的力量正慢慢覺醒。\n");
        set("unwield_msg", "$N放下這把劍時，那股強大的力量也慢慢的消失。\n");
        init_sword(70);
        setup();
}

