//u/c/chiaa/obj/eq/ten down_boots.c

#include <armor.h>
#include <ansi.h>
inherit BOOTS;
                        
void create()
{
    set_name(HIB"天"MAG"蕩"HIG"飄"NOR,({"ten down boots","boots"}) );
    set("long", "以某種材質製成.穿上之後就有如在天空般行走依樣的順暢。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(150);
                set("unit", "雙");
                set("value",1000);
                set("material","fur");
                set("armor_prop/armor",20);
                set("armor_prop/dodge",15);
                  }
      set("weapon_prop/dodge",15);        //加 enable 技能15
        setup();
}

