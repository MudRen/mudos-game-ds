#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit STAFF;
void create()
{
              set_name(HIB "地獄魔仗"NOR,({"abaddon-staff","staff"}));
              set("long","一隻圖形像是龍頭的魔仗，有著不可思異的破壞力，魔仗
裡也封印了足以稱霸武林的魔力，是一隻人人想要的寶物。\n");
              set_weight(5000);
                    set("material", "steel");
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "隻");
                    set("material", "wood");
                    set("value",500);
set("replica_ob",
"/u/k/king/area/npc/wp/stick");

                 }
set("wield_msg","$N向阿修羅冥思，阿修羅將一條靈魂灌入$N的身體裡，$N變的英勇無比。\n");
set ("unwield_msg","阿修羅雙手往天上一指，將魂魄收回了。\n");
                 init_staff(10);
set("combat_msg", ({
                    "$N雙手緊握"HIB"地獄魔仗"NOR"口唸咒語，一道火燄往$n的右手燒去。",
                    "$N舉起"HIB"地獄魔仗"NOR"往$n一指，一道天雷從天往$n擊下。",
"$N將自己的內力灌入"HIB"地獄魔仗"NOR"，"HIB"地獄魔仗"NOR"嗡嗡做響
，$N將"HIB"地獄魔仗"NOR"的第一封印解開，忽然一把鐮刀往$n的頭顱砍去。",
                    "$N對"HIB"地獄魔仗"NOR"展開冥思，忽然$N化身成一隻火龍，朝$n的右腳
猛噴火。",
                    "$N感應"HIB"地獄魔仗"NOR"的魔力，口唸十字真言：臨．兵．鬥．者．皆．
陳．列．在．前．破，$n的頭被十字真言所擾快要破裂。"    }) );
                                                             setup();
}
