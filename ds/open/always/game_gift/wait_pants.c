//由 /std/item/game_gift.c 創造 by -Acme-

#include <armor.h>
#include <ansi.h>
inherit PANTS;

void create()
{
        set_name( MAG"鬼爆"HIR"花邊褲"NOR, ({ "Crazy's pants","pants" }) );
	set_weight(3224);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","傳說中的鬼爆二人組，經歷無數場戰役所留下的一條花邊褲，仔細一看上頭染紅了敵人的鮮血，如果不注意看，還以為鬼爆的下體受了嚴重的創傷....");
		set("unit", "件");
		set("value",3608);
	}
	set("armor_prop/shield", 1);
	set("armor_prop/str", 1);
//        set("armor_prop/con", 2);
        set("armor_prop/con", 1); // 弄掉EQ的懲罰
	set("armor_prop/armor", 6);
	setup();
}
int query_autoload() { return 1; }
