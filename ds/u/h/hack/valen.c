//聖誕活動第三名 許茹芸(valen) 禮物 -by tmr-
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIC"如雲劍"NOR, ({ "valen sword","sword" }) );
        set("long",
"聖誕活動第三名 許\茹芸所得獎的禮物。\n"
"這是一把由劍尊竭盡畢生心血鑄造的劍，終年在山谷之中吸取天地精\n"
"華，似乎已有靈性，劍身散發出陣陣雲氣，彷彿與大自然相互呼應，在劍的劍\n"
"柄上刻有當年劍尊所撰寫的一首曲子，曲名為「如果雲知道」...."
);
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",1500);
                set("material", "iron");
                set("volume",3);
        }
        set("weapon_prop/int",1);
        set("weapon_prop/hit",5);
set("unwield_msg",HIC"$N放下如雲劍,身上的雲氣漸漸地消散,$N的身影漸漸變得清晰\n"NOR);
            set("wield_msg",HIC"$N拿起如雲劍,劍身上的雲氣逐漸圍繞著$N,使$N的身影變得撲朔迷離\n"NOR);
        init_sword(35);
      setup();
}

int query_autoload() { return 1; }

