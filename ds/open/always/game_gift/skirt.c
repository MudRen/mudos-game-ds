#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
	set_name(HIY"凝月長裙"NOR, ({ "moon skirt", "skirt" }));
	set_weight(3000);
	set("long", @long
這是一條潔白的長裙，散發著柔和的光芒。相傳為月宮娘娘親手用月光凝聚的絲所編之而成的。

端午節獎品 By -Alickyuen@The.Dream.Of.Seven-
-獎品名稱感謝玩家Watermoon@The,dream.of.seven提供-
long);
	set("unit", "條");
	set("value", 0);
        set("no_put", 1);
	set("no_give", 1);
        set("armor_prop/armor", 15);
        set("armor_prop/int", 3);
        set("armor_type", "pants");
	set("female_only", 1);

	setup();
}

int query_autoload() { return 1; }
