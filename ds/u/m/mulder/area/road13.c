// Room: /u/m/mulder/area/road13.c

inherit ROOM;

void create()
{
	set("short", "�o���� - �p��");
	set("long", @LONG
�A�{�b�i�ण�۫H���������A���O�i�A���u��i�H�䦳�A
���i�H��L�v���ߺA�V�e�i�o�D�߷Q��ݨ����Ǳ���u���ءA��
�O�ǻD������O�Q���j�l���A�����@�Ǫ��a��´�@�p���J�ӱ�
���o�ت�����A�����G�u���x�ШS�v�A�A�ݨ��a�W���@�ǩ_�Ǩ�
���D
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"shop2",
]));
	set("no_clean_up", 0);
	set("item_desc", ([
        "wheel" : "�@�ӤQ���_�Ǫ�����, �γ\\�A�i�H����ݡC\n",
        "����" : "�@�ӤQ���_�Ǫ�����, �γ\\�A�i�H����ݡC\n",
        ]));

	set("outdoors","land");
	setup();	
}
void init()
{
	add_action("do_roll","roll");
}	
	int do_roll(string arg)
{
	object me;
	me=this_player();
	if (arg != "����" && arg !="wheel" )
	return 0;

	else
	{
	message_vision("$N��ʨ����A�o�{�h�X�F�@�����è��J�h�C\n",me);
	me->move(__DIR__"road16");
	tell_room(environment(me),me->query("name")+"��ʨ����A�o�{�h�X�F�@�����è��J�h�C\n",me);
	return 1;
	}
}