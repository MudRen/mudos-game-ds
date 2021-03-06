// bandage.c

inherit ITEM;
inherit F_EQUIP;

void create()
{
	set_name("布條", ({ "cloth piece", "cloth", "piece" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "條");
		set("material", "cloth");
		set("armor_type", "bandage");
		set("armor_prop/attack", -10);
		set("armor_prop/defense", -10);
		set("armor_prop/unarmed", -10);
	}
}

void init()
{
	add_action("do_bandage", "bandage");
}

int wear() { return 0; }

int do_bandage(string arg)
{
	object ob;

	if( (int)query("blood_soaked") >= 2 )
		return notify_fail( name() + "已經被鮮血浸透﹐不能再用了。\n");

	if( query("equipped") )
		return notify_fail( name() + "已經裹在你的傷口上了﹐如果你要用來包紮別人﹐請你先把它除下來。\n");

	if( !arg ) ob = this_player();
	else {
		ob = present(arg, environment(this_player()));
		if( !ob || !ob->is_character() )
			return notify_fail("你要替誰裹傷﹖\n");
	}

	if( this_player()->is_fighting()
	||	ob->is_fighting() )
		return notify_fail("戰鬥中不能裹傷。\n");

	if( (int)ob->query("eff_kee") == (int)ob->query("max_kee") )
		return notify_fail( (ob==this_player()? "你" : ob->name())
			+ "並沒有受到任何外傷。\n");

	if( ob->query_temp("armor/bandage") )
		return notify_fail( ob->name() + "身上的傷已經裹著其他東西了。\n");

	if( !move(ob) ) return 0;

	if( ob==this_player() )
		message_vision("$N用" + name() + "替自己裹傷。\n", this_player());
	else
		message_vision("$N用" + name() + "替$n裹傷。\n", this_player(), ob);

	::wear();
	ob->apply_condition("bandaged", 40);
	add("blood_soaked", 1);

	return 1;
}

void remove(string euid)
{
	::remove(euid);
	if( query("equipped") && environment() )
		environment()->apply_condition("bandaged", 0);
}

string query_autoload()
{
	if( query("equipped") ) return query("name");
}

void autoload(string arg)
{
	int i;

	set("name", arg);
	set("blood_soaked", 3);
	::wear();
}

