#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
        set_name("碎骨寨項鍊", ({ "crush bone necklace","necklace"}) );
        set_weight(2000);

        if( !clonep() ) {
                set("unit", "條");
                  set("value", 600);
                set("long",@long
這是一條由碎骨寨中半獸人打造而成的項鍊，造型具有一種原始野性
的力量，但也提供給穿戴者不錯的防禦能力。
long
        );
                set("armor_prop/armo", 5);
		} else
		   set_default_object(__FILE__);
        setup();
}

