// Room: /d/xiangyang/kedian.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����ȴ�");
	set("long", @LONG
�o�O�@�a�樂��H�h�ӻ��ܦ��W�𪺫ȴ̡C�H�̨�������
�@�볣��b�o�̡A�@�O�K�y�A�G��ť�즿��W���\�h�Ʊ��C��
�~�ӡA�����h�ļƤQ���A�n�ӥ_�����H�̸g�L������O���y�b
�o��A���K���X�@�U���t���L�q���h�C
LONG );
        set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("valid_startroom", 1);

	set("exits", ([
		"east" : __DIR__"westroad1",
	]));
	set("objects", ([
		__DIR__"npc/wudunru" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
//	"/clone/board/kedian6_b"->foo();
}
