#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit DAGGER;
void create()
{
              set_name(HIY "七星"NOR"魔匕",({"devil-dagger","dagger"}));
              set("long","這是一把刻上北斗七星的匕首，每當月光照到匕首時，皇陵的
奇珍異寶的地圖將會浮現，無比鋒利的功能也是七星魔匕的一大特色。\n");
              set_weight(3000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "隻");
                    set("title",MAG "魔器"NOR);
                    set("material", "iron");
                    set("value",1000);
set("replica_ob",
"/u/k/king/area/npc/wp/dagger");

set("combat_msg", ({
"$N持著"HIY"七星"NOR"魔匕游走$n四方，忽然"HIY"七星"NOR"魔匕發出一陣光芒
讓$n一時眼睛失明，$N趁機往$n的肚子用力的刺下去。\n",
"$N流下一低無情的眼淚，低在"HIY"七星"NOR"魔匕上，從"HIY"七星"NOR"魔匕上
傳來一陣悲鳴，"HIY"七星"NOR"魔匕化成五隻厲鬼瘋狂的往$n的四肢咬去。\n",
"$N的鮮血灑在"HIY"七星"NOR"魔匕上，只見地上形成一個黑洞，阿修羅從地獄裡
飄了出來，手持無道戰戢往$n的心臟狠狠插了過去。\n"    }) );
          init_dagger(10);
setup();
}

}
