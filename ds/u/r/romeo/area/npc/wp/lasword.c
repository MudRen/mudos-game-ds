#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name("天"HIM"舞"NOR"寶輪",({"sky-dance","sword"}) );
        set("long","這是一個六角形的寶蓋，據說唸了咒語之後會變化自己想用的武器。\n");
          set_weight(2500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","把");
      set("value",1800);
        }
set("wield_msg",
"$N口唸：「佛∼動∼凡∼心」，從"天"HIM"舞"NOR"寶輪"中，發出一陣梵音，",
$N整個人被佛光圍繞，"天"HIM"舞"NOR"寶輪"由$n的右手進入$N的體內，跟$N",
$N整個人被佛光圍繞，"天"HIM"舞"NOR"寶輪"由$n的右手進入$N的體內，跟$N",
融為一體。\n");
              set("unwield_msg",""天"HIM"舞"NOR"寶輪"從$N的體內消失，回到了天界。\n");

set("combat_msg", ({
"$N盤旋坐在地上，口唸天竺梵文，一道"HIY"金"NOR"光罩在$n的頭上，好像萬劍齊發式的$n攻擊。\n",
"$N的四周泛出淡淡藍光，忽然從$N的口中飛出""HIB"佛"HIW"。"RED"殺"NOR""往$n的胸口殺去。\n",
"$N斥喝一聲，身後出現一尊佛像，從佛像的眼睛直中兩道"HIC"綠"NOR"光，朝$n射去。\n"  }) );
          init_SWORD(8);
        setup();
}

