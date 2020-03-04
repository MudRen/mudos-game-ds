// Modify with AreaMaker1.0
// Room42.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�����b�@�j������L�̡C�F�䦳�@�������D�O�ֶ}���p�B�D�A
�B�D�Q�����d�馱��C�o�̦��@�ʫܤj���Ѻ_��A���G�w�g���d�~��
���֤F�C�A����ť��@�}��䪺�n���A�j���O�]���̪�ӳҲ֦Ӧ��I
�ջ�a�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room32",
		"east": __DIR__"room43",
		"south": __DIR__"room52",
		"northwest": __DIR__"room31",
	]));

	set("hide_exits", ([
 	]));
	
	set("item_desc",([
        "tree":"�A�o�{�_���䦳�Ƿs�鸨������A���G�O���H��(climb)�W�h�y�����C\n",
        "�Ѻ_��":"�A�o�{�_���䦳�Ƿs�鸨������A���G�O���H��(climb)�W�h�y�����C\n",
         ]));
	
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
}

void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	return notify_fail("��A���n���𪺮ɭԵo�{��F�W�d�F�@�i�ȱ��C\n[�ϰ�}�o���A�Ш���!!]\n");
}