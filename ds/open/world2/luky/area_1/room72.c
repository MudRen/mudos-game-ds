// Modify with AreaMaker1.0
// Room72.c

inherit ROOM;

void create()
{
	set("short","��`");
	set("long", @LONG
�o�̬O�̲���򪺪F�`�C�F��M�_��O�@����L�A���䦳�\�h��
����A�٦��@�Ǥ��ͪ��p�ʪ��C�A�ݨ���䪺�d�פW���@�Ƕ콦�U�M
�������A�����D�O���ǥi�c���å�å᪺�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room62",
		"east": __DIR__"room73",
		"southeast": __DIR__"room83",
	]));
	 set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/bird0" : 1,
		__DIR__"npc/frog0" : 3,
	]));
	set("outdoors","land");		//��~(����)
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

