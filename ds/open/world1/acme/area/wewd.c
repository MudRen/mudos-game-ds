// Room: /u/a/acme/area/wewd.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�o�̬O���۷��䩵�����p���A�M�����ˤ��̥i�ݨ��p����y�C�ۦb��
��ۡA�A��_�M�D���ˤ��ܤF�@�f�A�J�f�̲��A�S�Ӥs�u�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"pons",
  "west" : __DIR__"pass7",
]));
	set("no_clean_up", 0);
    set("outdoors","land");

	setup();
	replace_program(ROOM);
}
