inherit ITEM;

void create()
{
	set_name("��l",({"dice"}) );
	set("long",@LONG
�@�ӥi�H���Y(roll)��������l�C���F���ӽ�դ��~�A�ݨӤ]�S
������γB�a�C
LONG
);
	set_weight(20);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
		set("value",10);
	}
	setup();
}

void init()
{
	add_action("do_roll","roll");
}

int do_roll(string arg)
{
	int m;
	object who;
	string num;
	who=this_player();

	if (arg != "dice") return 0;
	message_vision("$N�q�h�̮��X�@�ɻ�l�A�q���X�n����A�@���Y�b�a�W�C\n",who);
	m=random(6)+1;
	switch(m) {
		case 6:
			num="��";
			break;
		case 5:
			num="��";
			break;
		case 4:
			num="��";
			break;
		case 3:
			num="��";
			break;
		case 2:
			num="��";
			break;
		default:
			num="��";
	}
       message_vision("��l�w�ȷȦa��F�X�餧��A$N�Y�X�F �� �I\n",who);
	return 1;
}
