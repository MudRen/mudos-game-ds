// �i�v�L�����x
inherit ITEM;

void create()
{
	set_name("�ĥ|�i",({"forth magazine","magazine","forth"}) );
	set("long",@LONG
�o�O�@�����x...�W�s�u�ĥ|�i�v...�H...�H...�H...
LONG
	);
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",220);
		set("unit","��");
	}

	setup();
}

int can_copy()
{
	return 1;
}

int is_magzine()
{
	return 1;
}

