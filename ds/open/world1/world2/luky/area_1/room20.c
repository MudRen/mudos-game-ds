// Modify with AreaMaker1.0
// Room20.c

inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
�g�����򪺧j�ۡA�A�����ۧC����~��j�j��í�}�B�C���䦳�@
�ǯ}�ª��K���H���n�\�A���_�o�X�y�U��ժ��n���C�A�n�S�O�`�N�o
�����K���A�n�O��M�Q���j�_���L�ӥi�O�|�X�H�R���C
LONG
	);
	set("exits", ([
		"north": __DIR__"room10",
		"south": __DIR__"room30",
		"west": __DIR__"room19",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

