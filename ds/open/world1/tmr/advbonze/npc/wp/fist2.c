#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(HBK "不動無壽爪" NOR,({"bu-down wu-shou fist","fist"}) );
        set("long",@long
一個鐵鑄的精密爪子，上頭刻滿了卍字佛印，你拿在手上有種奇妙的
感應，對於世俗的塵事似乎看的比較開了。
long
        );
         set_weight(2000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","對");
                set("volume",2);
                set("material","iron");
                set("value",12000);
                set("limit_level",30);
                set("limit_str",50);
        }
        set("weapon_prop/hit",10);
        set("weapon_prop/bar",1);
        set("weapon_prop/sou",-1);
        set("weapon_prop/con",2);
        init_fist(50);

        setup();
}

