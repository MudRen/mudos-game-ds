#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
set_name( HIY "絕地邪刀" NOR ,({"jue dei blade","blade"}));
set("long","這是一把上頭刻著邪魔圖形的魔刀，泛著一股魔氣。\n");
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",2000);
set("volume",3);
set("limit_str",13);
set("limit_dex",11);
        }
set("wield_msg","$N從背後抽出一把$n握在手中,但見$N面目猙獰，全身散著黑氣。\n");
set("unequip_msg", "$N放下手中的$n, 將$n插入背後劍鞘中。\n");

set("combat_msg", ({
   "$N一招「魔光四射」，劍尖四點，分點$n的眉間、前胸、後心、大腿。\n\n",
   "$N一式「鬼影幢幢」，形如鬼魅，浮遊不定，突然從$n眼前冒出，只見$n嚇得被自身武器插進左眼。\n\n",
   "$N突然狂舞手上邪刀，似是癲狂，一招「群魔亂舞」，猛攻$n，只見$n臉色鐵青，不能自我。\n\n",
}) );
init_blade(32);
setup();
}
