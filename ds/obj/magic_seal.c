// magic_seal.c

inherit ITEM;

void create()
{
	set_name("�ũG", ({"seal"}) );
	set_weight(5);
	set("long",
		"�o�O�@�i�e�n���ũG�M�� attach ���O�i�H�N���K�b�Y�H(�άY��)���W�C\n");
	set("unit", "�i");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}

void init()
{
	add_action("do_attach", "attach");
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob;
	function f;

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
		return notify_fail("���O�榡�Rattach <�ũG> to <�ؼ�>\n");
	
	if( !id(sheet) ) return 0;

	ob = present(dest, this_player());
	if( !ob ) ob = present(dest, environment(this_player()));
	if( !ob ) return notify_fail("�A�n�擄��F��ϥγo�i�ũG�S\n");

	if( !functionp(f = query("attach_func", 1)) )
		return notify_fail("�o�i�ŨS���ΡC\n");

	if( evaluate(f, ob) ) {
		if( ob!=this_player() )
			message_vision("$N���X�@�i" + name() + "��$n�@�K�C\n", this_player(), ob);
		if( ob && ob->is_character() ) {
			move(ob);
			set("equipped", "sealed");
			set("no_drop", "�o�˪F�褣����M������ detach�C\n");
		} else destruct(this_object());
		return 1;
	} else 
		return 0;
}
