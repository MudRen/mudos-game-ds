#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create()
{
        set_name(HIR"聖誕"HIW"歡樂戒指"NOR, ({ "christmas ring","ring" }) );
        if( clonep() )
        set_default_object(__FILE__);
        else {
  set("long",@LONG
這是一只２００６年聖誕活動的歡樂戒指，戒指上嵌著一粒耀眼的紅寶石。
LONG
);
                set("unit", "只");
        set("value",1);
        set_weight(1);
        set("material","gold");
         set("armor_prop/int",1 + random(3) );
         set("armor_prop/str",1 + random(3) );
         set("armor_prop/dex",1 + random(3) );
         set("armor_prop/con",1 + random(3) );
         set("armor_prop/armor", 5 + random(20) );
        }
        setup();
}

