// Room: /ruzhou/jiulou1.c
// YZC 1995/12/04 llm 99/07

inherit ROOM;

void create()
{
	set("short", "�ﻫ��");
	set("long", @LONG
���Ʀʨ����A�ﻫ�Ӫ��W��i�׬O���p�C�Ӧ����}���W�h����
�]�����D�Ч@�֡A�y�U���֥O��o�N���F��C�ӤU���m²���A�U�Ȧh
�O�^�^����H�A�R�I�]�l�A���L�B�̰s�N�����h�F�C�ӤW�O�M���|��
�����B�b���ߺְ�C
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaozheng",
		"up" : __DIR__"xifu-tang",
	]));

	set("objects", ([
      __DIR__"npc/xiaoer" : 1,
	]));

	setup();
	replace_program(ROOM);
}

