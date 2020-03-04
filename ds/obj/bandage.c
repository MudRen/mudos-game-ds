// bandage.c

inherit ITEM;
inherit F_EQUIP;

void create()
{
	set_name("����", ({ "cloth piece", "cloth", "piece" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
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
		return notify_fail( name() + "�w�g�Q�A����z�M����A�ΤF�C\n");

	if( query("equipped") )
		return notify_fail( name() + "�w�g�q�b�A���ˤf�W�F�M�p�G�A�n�Ψӥ]�ϧO�H�M�ЧA���⥦���U�ӡC\n");

	if( !arg ) ob = this_player();
	else {
		ob = present(arg, environment(this_player()));
		if( !ob || !ob->is_character() )
			return notify_fail("�A�n���ֻq�ˡS\n");
	}

	if( this_player()->is_fighting()
	||	ob->is_fighting() )
		return notify_fail("�԰�������q�ˡC\n");

	if( (int)ob->query("eff_kee") == (int)ob->query("max_kee") )
		return notify_fail( (ob==this_player()? "�A" : ob->name())
			+ "�èS���������~�ˡC\n");

	if( ob->query_temp("armor/bandage") )
		return notify_fail( ob->name() + "���W���ˤw�g�q�ۨ�L�F��F�C\n");

	if( !move(ob) ) return 0;

	if( ob==this_player() )
		message_vision("$N��" + name() + "���ۤv�q�ˡC\n", this_player());
	else
		message_vision("$N��" + name() + "��$n�q�ˡC\n", this_player(), ob);

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

