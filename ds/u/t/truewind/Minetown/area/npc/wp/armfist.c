#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
        set_name(WHT"肩甲拳"NOR,({"Arm fist","fist"}) );
        set_weight(5000);
        set("long",@long
一副和鋼鐵肩甲一體成型的攻擊武器，能夠利用本身的重量加強給予對手的傷害。
long
        );
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",1500);
        set("unit","副");
        set("wield_msg","$N使勁甩了甩身子，披起$n。\n");
        set("material","iron");
        init_fist(30);
        set("weapon_prop/armor",10);
        }
        setup();

}