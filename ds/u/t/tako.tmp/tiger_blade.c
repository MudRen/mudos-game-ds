#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
set_name( HIY "虎魄" HIW"神刀"  NOR ,({"tiger blade","blade"}));
set("long","這是一把由 蚩尤 親自打造的刀,需要殺滿七七四十九人的血
            再由一隻老虎喝下,等待老虎雙眼便紅,無時咆哮時,再將它的
            脊椎抽出,血液附著,隨之而乾,變成一把略呈黃透明的刀,威力
            無窮,若控制的不好,必遭受 虎魄 反嗜的命運。\n");
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",2000)
;
set("volume",2);
}
set("limit_str",30);
set("limit_dex",32);
set("limit_int",23);
set("wield_msg",
"$N從背後抽出一把$n握在手中,只見$n發出黃色的光芒,沖滿著無限的殺氣 。\n");
set("unequip_msg", "$N放下手中的$n, 將$n插入背後的刀鞘中,殺氣漸漸不見。\n");
set("combat_msg", ({
   "$N一式「毀天」，刀尖發出紅色靈光,  上劈$n雙肩，下砍$n額骨之間 "  ,
   "$N雙腳一耀，高高耀起，由上俯衝而下,全身呈白色的氣霧， 一式「滅地」\n
  ，往$n的腰際斬去",
   "$N轉身扶地，隻手撐身，旋轉而上$N從$n背後竄出，一式「毀天滅地」,$N\n
    身上發出強大的皇者霸氣上劈下斬,凌亂不堪的往$n的全身上下而去\n   
    ,$n彷彿看到兇猛的野獸",
   "$N起身運氣,把手中虎魄往$n的方向丟去,一式 「盪浪」,虎魄由左旋斬至右,往$n
    的雙腳而去,$n哀號一聲",
   "$N張開嘴對著$n咆哮一聲,一式「吞噬」有如猛虎的吼聲,震盪的回聲遲遲不消\n
    的像萬把的刀,往$n的雙耳而去",
   "$N把刀一轉,一式 「射日」,防不勝防的往$n刺去,$n把持不住,被$N壓制在地上,\n
     $N轉身後耀,馬上,一式 「雷斬」,$N由空疾下,持虎魄左右趨之",
   "$N把虎魄反向使用,轉為刀柄操之,一式 「洩風」,$N用力的把虎魄往$n身上\n
     掃去,$n的周圍起了一道巨風,把$n轉到了$N的身旁,$N馬上一式「毀天」,刀尖\n
     發出紅色靈光,  上劈$n雙肩，下砍$n額骨之間 "  ,
     "$N起身運氣,把手中虎魄往$n的方向丟去,一式 「盪浪」,虎魄由左旋斬至右,往$n
    的雙腳而去,$n哀號一聲但被$n閃了過去,$N接著下使,一式 「雷斬」,$N由空疾\n
     下,持虎魄左右趨之",
     "$N把虎魄反向使用,轉為刀柄操之,一式 「洩風」,$N用力的把虎魄往$n身上\n
     掃去,$n的周圍起了一道巨風,把$n轉到了$N的身旁,$N接著一式「吞噬」有如\n
     猛虎的吼聲,震盪的回聲遲遲不消的像萬把的刀,往$n的雙耳而去",
}) );
init_blade(65);
setup();
}


