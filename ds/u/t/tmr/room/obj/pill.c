// black_pill.c
inherit ITEM;
void create()
{
	set_name("烏心丹", ({"black pill", "pill"}));
	if( !clonep() ) {
		set("unit", "些");
		set("long",
			"烏心丹是一種民間很普遍的藥方﹐用來恢復因操練、工作所耗的體力\n"
			"有不錯的效果﹐缺點是吃了以後會昏昏沈沈想睡覺﹐且容易口渴。\n");
		set("unit", "粒");
		set("value", 80);
		set("weight", 5);
	}
	setup();
}
