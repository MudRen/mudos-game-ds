// Room: /d/xiangyang/jiangjunyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�N�x���j�|");
	set("long", @LONG
�o�̬O�N�x�����j�|�A�u���j�z�۾Q�N���a���@�Ф��V�A
��Ӧ�ۥ��A���p�X�U�{�u���b���~���䪺����M�W�l�A����
���ȯZ���äh���L�ӡC�V�̱�h�A�i�H�ݨ�N�x�����j��C
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"jiangjungate",
		"north" : __DIR__"jiangjuntang",
	]));
	set("coor/x", -490);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}