// caodi2.c ��a
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
		"west"      : __DIR__"caodi",
		"southeast" : __DIR__"hanshuitan",
	]));
	set("objects", ([
		__DIR__"npc/yufeng" : random(3),
                __DIR__"npc/butterfly" : 2+random(2),

	]));
	setup();
	replace_program(ROOM);
}
