#include <armor.h>
#include <ansi.h>

inherit MASK;

void create()
{
	set_name(HIY"凝月玉面"NOR, ({"moon mask" ,"mask" }));
	set_weight(3000);
	set("long", @long
這是照了千年月光的玉刻製成的面具，具有神奇的力量，只要覆蓋在臉上，自然會與覆蓋的人成為一體。

端午節獎品 By -Alickyuen@The.Dream.Of.Seven-
-獎品名稱感謝玩家Watermoon@The,dream.of.seven提供-
long);
	set("unit", "塊");
	set("value", 0);
        set("no_put", 1);
	set("no_give", 1);
        set("armor_prop/armor", 5);
        set("armor_prop/con", 3);
	set("armor_type", "mask");

	setup();
}

int query_autoload() { return 1; }

