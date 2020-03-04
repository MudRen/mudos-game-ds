#include <weapon.h>
#include <ansi.h>
inherit SSERVER;
inherit BLADE;
void create()
{
        set_name(WHT "天邪刀" NOR,({"tan-chan blade","tan-chan","blade"}) );
        set("long",
        "這是一柄薄如紙，利如刃，能削鐵如泥的魔刀。這\n"
        "這柄刀傳說是地邪天佬給天殘邪佬打落迷宮之後，\n"
        "地邪天佬將迷宮內的特殊礦石練製而成的。傳說中\n"
        "地邪天佬用了百年來鑄造此刀，被號稱”天下第一\n"
        "刀。但還沒有人尋得此刀下落，亦被武林人士流傳\n"
        "”見刀者死”的傳聞。\n"
);
        set_weight(20000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","柄");
          set("value",100000);
                set("limit_str",45);
                set("limit_con",40);
                set("limit_int",30);
                set("limit_dex",30);
                set("limit_skill",80);
                set("wield_msg","$N裝上$n,$N感到有一股邪氣運行$N的身體！");
                set("unwield_msg","$N放下了$n,$N的邪氣轉回刀中。");
        }
        set("weapon_prop/hit", 30);
        set("weapon_prop/dodge",-2);
        set("weapon_prop/bar",5);
        set("weapon_prop/bio",5);
        set("weapon_prop/tec",-4);
        init_blade(60);
        setup();
}
