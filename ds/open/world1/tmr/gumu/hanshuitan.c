// hanshuitan.c �H����
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_qian(string arg);

void create()
{
	set("short", "�H����");
	set("long", @LONG
�o���O��a����t�A�C��w�g�ܵ}���F�A���M���@�G�ɸ��Ӧ^�a��
�L�M�V�����C�A�����e�O�@�ӲM�i���y���j���� (tan)�A�����M�ӤU�A
�����x�_�F�@�D�C��m�i�A��۳o������A�A�U���ɮ��C
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northwest" : __DIR__"caodi2",
	]));
	set("objects", ([
          __DIR__"npc/yufeng" : 4,
	]));
	set("item_desc", ([
		"tan": "����ܲM�A�����i�H���L�������ǥ��b�}�A�@�G�峽���a�q������L�A�S�����D����������Y�Z���è��h�F�C\n",
	]) );
	setup();
	replace_program(ROOM);
}

