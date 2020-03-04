#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIY "六邪靈劍" NOR ,({"six-devil sword","sword"}));
set("long","這是一把岳陽樓代代相傳的一把帶有邪氣的劍。\n");
set_weight(11100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",2456);
set("volume",2);
set("limit_str",30);
set("limit_dex",24);
        }
set("wield_msg","$N從腰上抽出一把$n握在手中,但見$N劍鋒邪氣不斷，全身散著妖氣。\n");
set("unequip_msg", "$N放下手中的$n, 將$n插入背後劍鞘中。\n");

set("combat_msg", ({
   HIY"$N一招「邪靈照明月」，劍氣一分四，斬向$n的腰子、健肌、小腿、大腿。\n"NOR,
    HIC"$N一式「血光濺四周」，劍氣模糊不清，浮遊不定，突然從$n眼前冒出了邪氣，搓向$n
    去了。\n"NOR,
 HIW"$N突然狂舞手上靈劍，帶有殺氣的，一招"HIY"「狂魔龍皇斬」，猛攻$n，只見$n臉色鐵青，不能
自我。\n"NOR,
}) );
init_sword(66);
setup();
