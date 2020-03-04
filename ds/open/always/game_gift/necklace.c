#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
	set_name(HIY"凝月靈符"NOR, ({ "moon necklace", "necklace" }));
	set_weight(3000);
	set("long", @long
這道是由吸納月光的力量而煉製成的一道符。相傳佩帶在身上，能得到月光的闢護。

端午節獎品 By -Alickyuen@The.Dream.Of.Seven-
-獎品名稱感謝玩家Watermoon@The,dream.of.seven提供-
long);
        set("unit", "個");
	set("value", 0);
        set("no_put", 1);
	set("no_give", 1);
        set("armor_prop/armor", 8);
	set("armor_type", "neck");

	setup();
}

int query_autoload() { return 1; }

void init()
{
        object me= this_player();

	if( !me) return;

        if( environment(this_object()) == me )
        {
                if( !this_object()->query_light() ) this_object()->start_light(1);
        }
	else this_object()->start_light(0);
}
