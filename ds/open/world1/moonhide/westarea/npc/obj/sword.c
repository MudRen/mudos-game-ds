#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name( "雷劍" ,({"thunder sword","sword"}) );
        set("long","這是雷神爾涅爾的隨身武器，劍身呈四十五度彎曲，犀利非常。\n");
        set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","把");
        set("value",4300);
        set("volume",5);
        set("material","iron");
        init_sword(43);
        }
        setup();
}


