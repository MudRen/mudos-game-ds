#include <weapon.h>

inherit BLADE;

void create()
{
set_name("真•西瓜刀",({"watermelion blade","blade"}));
set("long","這本來是用來切西瓜的刀子,但是被混混拿來當幹假的工具.\n");
set_weight(7800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "把");
set("value",300);

set("material","iron");
set("limit_str",5);
set("limit_dex",5);
        }
set("wield_msg","$N從一捆報紙中抽出一把鋒利的$n\n");
set("unwield_msg", "$N放下手中的$n, 用報紙包好收藏起來。\n");
init_blade(15);       
set("combat_msg", ({    
"$N手拿$w，一聲X你娘，往$n的頭劈了過去，$n的頭當場血流滿注",
"$N忽見情勢不妙，趕快忽叫同夥，一聲號令之下，只見一群人衝出來，見到$n就是一頓亂打",
"$N大罵:「還沒斷奶就想在這裡搶地盤?」，於是$n就嚇破膽了，你再趁虛而入，踹了$n一腳",
"$N你趁$n想逃跑的時後 ，在$n後面補了一刀",
"$N用刀抵住$n的脖子，順便拿旁邊不知哪來的磚塊往$n的頭敲到腦陣當",}) );
setup();
}
