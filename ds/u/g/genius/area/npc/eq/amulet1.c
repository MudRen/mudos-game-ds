#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIG"神秘綠寶石護身符"NOR, ({ "tourmarlina amulet","amulet" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","這條項鍊掛了一個綠寶石的墜子，發出閃爍的光芒，十分的耀眼。\n");
                set("unit", "條");
                set("value",1);
                set("material","diamond");
        }
        set("armor_prop/int",3);
        set("armor_prop/armor",20);
        set("armor_prop/shield",10);
        setup();
}
