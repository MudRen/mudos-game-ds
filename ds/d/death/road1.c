// Room: /d/death/road1.c

inherit ROOM;

void create()
{
	set("short", "�����j�D");
	set("long", @LONG
�A���b�@�����˴˪����W, �@�@������¶�b�A���|�P, �n����
�������|���h����. ���n�ݥh�A�j�j�i�H����X�@�ӫ��Ӫ��Ҽ�,
���_�����i�H�ݨ�X���OŢ, �b�@������o��~���޲�. �������
�U���@�ɤ�y���ؿv, �����O�b�}��, ���A�ݤ��M���̭�������.

LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/death/road2",
  "south" : "/d/death/gateway",
  "west" : "/d/death/inn1",
  "east" : "/d/death/inn2",
]));

	setup();
}

