// Modify with AreaMaker1.0
// Room55.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�o�̬O���̧A�]���ӲM���A�F�䦳�Ӧ���צ�F�A���h���C�A��
�����W�}�F�@�ӯ}�ª����f�M�A�W���٦��@���p���I���������b�W
���H�M�}�y�ۡA�Pı�Q���d�G�Y�D�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room45",
		"south": __DIR__"room65",
		"west": __DIR__"room54",
		"northeast": __DIR__"room46",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

