// caodi.c ��a
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "��a");
	set("long", @LONG
�o���O�@����a�A��ܲ`�A�X�G�T�S�F�p�L�C�󶡴����ۤ@�ǩ_��A
�L���j�L�A��ڼ���C�Ať��ɦӦ������䡨���n���A�ݨ����@�ǭ�
�Y�_�j���զ⪺�e���b��a�W���R�L�ۡC
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"south" : __DIR__"mumen",
		"east"  : __DIR__"caodi2",
		"north" : __DIR__"shulin3",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : random(5),
	]));

	setup();
	replace_program(ROOM);
}
