//掌上遊戲第一屆比賽 第一名 eji 獎品 -by tmr- 2000/5/20

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name("閒雲", ({ "eji sword","sword" }) );
        set("long",@long
掌上遊戲第一屆比賽 第一名 eji 獎品
    這是一把為eji專做的劍，劍看起來平平無奇，
但是如果你仔細觀察，會發現竟然會有一抹淡淡的
藍光在劍身上流轉，在劍柄上刻著閒雲兩字。
long
);
            set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value",1500);
                set("material", "iron");
                set("volume",3);
        }
        set("weapon_prop/hit",5);
      set("wield_msg","瞬間藍光流轉包圍著$N和劍，一陣子後恢復平淡。\n");
          set("unwield_msg","$N手中藍影一閃，劍已回到劍鞘。\n");
        init_sword(20);
        setup();
}

int query_autoload() { return 1; }
