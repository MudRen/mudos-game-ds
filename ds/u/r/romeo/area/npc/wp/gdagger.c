#include <weapon.h>
inherit F_UNIQUE;
#include <ansi.h>
inherit DAGGER;
void create()
{
              set_name(HIM "屢屢"NOR"幻煙",({"devil-smoke-move","smoke","move"})
);
              set("long","這是一陣虛幻的迷煙，不知道是有什麼功能。\n");
              set_weight(3000);
              if( clonep() )
                      set_default_object(__FILE__);
              else {
                    set("unit", "隻");
                    set("material", "iron");
                    set("value",1000);
set("replica_ob",
"/u/k/king/area/npc/wp/dagger");

                    set("wield_msg","一股輕煙輕輕的包圍你的右手，之後化成一個佛印，印在你的手上。");
                    set ("unwield_msg","一陣暈眩之後，佛印從你的手上消失了。");
                    set("combat_msg", ({
"$N持著"HIM"屢屢"NOR"幻煙形成一陣鋸風往$n的腹部刺去。",
"$N將"HIM"屢屢"NOR"幻煙往自己的手腕割出一道血痕，"HIM"屢屢"NOR"幻煙吸到
血之後忽然一陣悲鳴，從天上降下一道崩雷，往$n擊去。",
""HIM"屢屢"NOR"幻煙變成一隻大槌子往$n的肩膀敲下。",
""HIM"屢屢"NOR"幻煙化成天照大神，出現在$n面前，$n做賊心虛馬上跪了下去，
天照大神面露微笑的將憾天劍往$n的天靈刺下。"    }) );
          init_dagger(10);
setup();
}

}

