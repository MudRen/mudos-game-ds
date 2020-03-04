inherit ROOM;
void create()
{
	set("short", "������");
	set("long",@LONG
�o�̬O�����U�A�b�o�̦��@�ǨǪ��ͪ��A���O�C��@�����A���b�V
�A�ʥʤj�s�A���L�L��A�Ө��S������ˮ`�O�i���A�Ӧb�_��O�����A
�q���������y�y�L�ӡA�b�o�̪����䦳�����a�A���G�i�H��(scrape)
���ˤl�C
LONG
	);
	set("exits", ([
  "north" : __DIR__"well.c",
]));
	set("item_desc", ([
  "���a" : "���b���t�a�誺�@�شӪ�, �e��.\n",
]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_scrape","scrape");
}

int do_scrape(string arg)
{
	object me;
	me = this_player();
	if( random(100) > 50 && !query_temp("musci") )
	{
		write("�A��U�F�@�ǨǪ��A�a�C\n");
		new(__DIR__"npc/obj/musci.c")->move(me);
		set_temp("musci",1);
		set("long",@LONG
�o�̬O�����U�A�b�o�̦��@�ǨǪ��ͪ��A���O�C��@�����A���b�V
�A�ʥʤj�s�A���L�L��A�Ө��S������ˮ`�O�i���A�Ӧb�_��O�����A
�q���������y�y�L�ӡC
LONG
		);
		call_out("delay",600,this_object());
	}
	else
	{
		write("..... �A�κɥ��O�٬O���U�ӡC\n");
	}
	return 1;
}

void delay(object tob)
{
	delete_temp("musci");
	set("long",@LONG
�o�̬O�����U�A�b�o�̦��@�ǨǪ��ͪ��A���O�C��@�����A���b�V
�A�ʥʤj�s�A���L�L��A�Ө��S������ˮ`�O�i���A�Ӧb�n��O�����A
�q���������y�y�L�ӡA�b�o�̪����䦳�����a�A���G�i�H��(scrape)
���ˤl�C
LONG
	);
	return;
}
