// Room: /u/s/suez/grave/path_2.c

inherit ROOM;

void create()
{
	set("short", "�y�s�p�D");
	set("long", @LONG
�d�骺�y�s�p�D�������b�o�̰���F�A���Y��h�A�y�s�s���������b
�W�A���M���n���@�p�ѤU�A�����G�L���i��C�Ѧ���h�A�y�s�����A�~��
�p�C�A�������k�A�M�Ѥs�U�ܦ����@�����p���A�گ�̨̬O�j�����A
����i�ܪ��ѱV�A�䭷�����R�������٤@���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"path_3",
  "west" : __DIR__"path_1",
]));
        set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
