#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(BLU"深凍石"NOR, ({ "ice stone","stone" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一個散發著奇寒的小石子\n");
                set("unit", "只");
        set("value",10000);
        set_weight(600);
         set("material","jade");
         set("armor_prop/int",1);
        }
        set("wear_msg",HIW"$N忽然被深凍石放出的寒氣包圍！"NOR);
        set("remove_msg", "$N深凍石的寒氣漸漸散去了...。");
        setup();
}
