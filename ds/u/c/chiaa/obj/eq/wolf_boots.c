//u/c/chiaa/obj/eq/wolf_boots.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;
void create()
{
    set_name(YEL"狼"HBK"靴"NOR,({"wolf boots","boots"}) );
    set("long", "穿上它就像在大草原上的狼一樣敏捷。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(200);
                set("unit", "雙");
                set("value",300);
                set("material","fur");
                set("armor_prop/armor",10);
                set("armor_prop/dodge",10);
                  }
      set("weapon_prop/dodge",15);        //加 enable 技能5
        setup();
}
