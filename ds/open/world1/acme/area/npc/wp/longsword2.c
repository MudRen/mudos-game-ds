#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( HIC "錦衣劍" NOR ,({"gin yi sword","sword"}));
        set("long","這是朝廷裡尋常禁軍所佩帶的長劍，十分輕巧，卻又鋒利。\n");
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "把");
         set("value",2000);
set("volume",3);
        }
        set("limit_str",10);
        set("weapon_prop/str",1);
        set("weapon_prop/hit",5);
        set("wield_msg","$N從背後抽出一把$n握在手中,但見$n光芒四射，相當刺眼。\n");
        set("unequip_msg", "$N放下手中的$n, 將$n插入背後劍鞘中。\n");
        init_sword(36);
        setup();
}
