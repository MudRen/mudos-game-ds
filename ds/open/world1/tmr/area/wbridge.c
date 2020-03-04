// Room: /u/wbridge.c

inherit ROOM;

void create()
{
	set("short", "����W");
	set("long", @LONG
�@������������A���@���e�y�A���L�ݨӪe���Z��������h�T�|��
�A�N�ⱼ�U�h�]�L�����A�]���|�Q�o���e�y�ҨR���C���n��O�@�y�p�s��
�A���_��O����D�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"square",
		"north" : __DIR__"street3",
]));
    set("objects", ([ __DIR__"npc/shan.c": 1 ]) );

	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
