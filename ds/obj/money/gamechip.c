// gamechip.c			Shengsan@DS	1999.4.4
// 籌碼

inherit MONEY;

void create()
{
	set_name("籌碼", ({ "gambling chip", "chip", "game_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "這是在遊樂場才能使用的代幣。\n");
		set("unit", "些");
		set("base_value", 1);
		set("base_unit", "枚");
		set("base_weight", 1);
		set("base_volume", 0.002);
	}
	set_amount(1);
}
