#include <armor.h>
#include <ansi.h>
inherit MASK;
void create()
{
	set_name("生命感測鏡", ({ "life-detect glasses","glasses" }) );
	set("long",@LONG
這副眼鏡內含壓力計與溫度計，可以偵測到使用者的生命狀態與相關情報。
LONG
);
	set_weight(930);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "副");
		set("material", "glass");
	}
	set("armor_prop/armor",2);
	set("armor_prop/show_damage",1);
	setup();
	set("value",1200);
}

//int query_autoload() { return 1; }
