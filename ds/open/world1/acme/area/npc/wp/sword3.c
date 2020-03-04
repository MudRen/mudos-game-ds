#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
set_name( HIB "戰天神劍" NOR ,({"zhan tian sword","sword"}));
set("long","這是一把上頭刻著太陽圖騰的寶劍，看起來似乎攻擊力不弱。\n");
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",2000)
;
set("volume",2);
}
set("limit_str",12);
set("limit_dex",14);
set("wield_msg","$N從背後抽出一把$n握在手中,但見$n光芒四射，相當刺眼。\n");
set("unequip_msg", "$N放下手中的$n, 將$n插入背後劍鞘中。\n");
set("combat_msg", ({
   "$N一招「毀天滅地」，劍招極為凌厲，\n  上刺$n雙眼，下刺$n二股之間"  ,
   "$N雙腳一蹬，高高躍起，由上俯衝而下，\n  一招「天龍降世」，往$n的頭頂插去",
   "$N遊移風轉，捉摸不定，倏地$N從$n背後竄出，\n  一式「東昇西墜」，往$n刺去",
}) );
init_sword(35);
setup();
}
