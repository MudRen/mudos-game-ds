// Room: /u/a/acme/area/pass5.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�O�@���W�s���p�|�A�a�W��B�i�������\���������A�|�P�ͪ��F��
�j����A�@���ѤѡA���q�J���A���ѽ���A�����_�[�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"pass4",
  "westdown" : __DIR__"pass6",
  "northwest" : __DIR__"f1",
]));
	set("no_clean_up", 0);
     set("outdoors","land");

	setup();
	replace_program(ROOM);
}
