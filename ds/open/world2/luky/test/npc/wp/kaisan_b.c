#include <weapon.h>

//DEFAULT_WEAPON_LIMB "右手"
//TWO_HANDED	1
//SECONDARY	2
//EDGED		4
//POINTED	8
//LONG		16

//AXE			"/std/weapon/axe"
//BLADE			"/std/weapon/blade"
//DAGGER		"/std/weapon/dagger"
//FORK			"/std/weapon/fork"
//HAMMER 		"/std/weapon/hammer"
//SWORD			"/std/weapon/sword"
//STAFF			"/std/weapon/staff"
//THROWING		"/std/weapon/throwing"
//WHIP			"/std/weapon/whip"

//F_AXE			"/std/weapon/_axe"
//F_BLADE		"/std/weapon/_blade"
//F_DAGGER		"/std/weapon/_dagger"
//F_FORK		"/std/weapon/_fork"
//F_HAMMER 		"/std/weapon/_hammer"
//F_SWORD		"/std/weapon/_sword"
//F_STAFF		"/std/weapon/_staff"
//F_WHIP		"/std/weapon/_whip"

inherit BLADE;

void create()
{
set_name("開山刀",({"kaisan blade","blade"}));
set("long","這是一把方頭的鐵製黑色長刀,拿這種刀的人通常不是什麼好人.\n");
set_weight(7600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",290);

set("material","iron");
//
// 條件可以是 	limit_lv 	limit_str 
//		limit_dex 	limit_con 
//		limit_int 	limit_skill
//
set("limit_str",5);
set("limit_dex",6);
        }
set("wield_msg","$N從一捆報紙中抽出一把鋒利的$n\n");
set("unwield_msg", "$N放下手中的$n, 用報紙包好收藏起來。\n");
//  weapon_prop/dex
//  weapon_prop/str
//  weapon_prop/int
//  weapon_prop/con
//  weapon_prop/hit	命中率
//  weapon_prop/parry	招架率
//  
init_blade(14); 	// 傷害力=set("weapon_prop/damage", 14);
set("combat_msg", ({    //攻擊訊息 $N是自己 $n是對方 $l 是對方受攻部位 $w是武器名稱
"$N手握$w﹐眼露兇光﹐猛地對準$n的$l揮了過去",
"$N的$w往$n的$l狠狠地一捅",
"$N用$w往$n的$l刺去",
}) );
setup();
}
