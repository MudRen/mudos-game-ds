// Modify with AreaMaker1.0
// Room65.c

inherit ROOM;

void create()
{
	set("short","��L");
	set("long", @LONG
�A�@����o�̴N�ݨ�F�@�ӱ�X�A�X�Ӥw�g�ܤ[�S�M�z�F�ҥH��
�e���o�{�C�A�ܦ۶Ʀۤv���p���R�Q���[��O�A���M�ߤ����Ǥ��
�A���L�A�٬O���W�e�h�ѫ��F�@�|��C�����٦��@��CD���A���G�O��
�����Ĥ@�i�M��A�����D�O�֥�b�o�̪��C
LONG
	);
	set("exits", ([
		"north": __DIR__"room55",
		"south": __DIR__"room75",
		"northwest": __DIR__"room54",
	]));
 	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

