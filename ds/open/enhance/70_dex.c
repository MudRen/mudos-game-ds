#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( GRN "７０％敏捷卷" NOR, ({"70p dex scroll","scroll"}) );
        set("long",@LONG
這是一張具有神奇效果的卷軸，可以用來強化武器及防具。
使用指令，請參考 help enhance。
相關設定，請參考 help scroll。
LONG);
	set_weight(10);
	set("value",1000);
	set("unit","張");
	
	set("is_enhance",1); // flag
	set("eff_p", 70);	// 成功機率
	set("eff_type", "dex");

	setup();	
}

int query_autoload() { return 1; } 



