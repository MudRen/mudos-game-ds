// suya.c
// 她是一位美達星人, 以心靈攻擊為主

inherit NPC;

void create()
{
	set_name("素雅",({"suya","meda"}));
	set("race", "美達人");
	set("gender", "女性");
	set("long","她擁有俏麗的身材及個性美的心腸，她是位美達星人。\n");
	set("level",25);
	set("age",27);
   	setup();
}
