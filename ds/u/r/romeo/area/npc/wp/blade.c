#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
set_name(HIR "紅魔""邪"HIB"刀"NOR, ({"evil-blade", "balde" }) );
        set("long",
        "這是一把天火老魔心愛的寶刀擁有邪惡的力量，是一
把很可怕的刀。\n"
        );
          set_weight(100);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
                set("value",200000);
                set("material", "iron");
set("wield_msg",HIW"$N拔出$n，"NOR"一道紅霧從刀散了出來，迅速的鑽入你的
鼻孔，你眼中發出紅色的殺氣，一副如鬼神的模樣。\n");
set("unwield_msg", "你的力量開始渙散。\n");    }
                set("material","iron");
                set("waepon_prop/int",1);
                set("weapon_prop/str",3);
                set("weapon_prop/dex",1);
        set("limit_str",10);
setup();
               init_blade(100);
}
