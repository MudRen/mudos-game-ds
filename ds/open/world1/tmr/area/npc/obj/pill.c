inherit ITEM;
inherit F_PILL;
void create()
{
	set_name("大補丹", ({ "heal pill", "pill" }));
	set("long",@LONG
大補丹是一種民間很普遍的藥方﹐用來恢復因操練、工作所耗的體力
有不錯的效果﹐缺點是吃了以後會昏昏沈沈想睡覺﹐且容易口渴。
LONG
);
	set_weight(300);
	if( clonep() ) 
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
	}
        set("value", 240);
	set("heal",([ "hp" : 80, ]));
	setup();
}
