// Room: /u/m/mulder/area/inn.c

inherit ROOM;

void create()
{
	set("short", "�s���o�ȩ�");
	set("long", @LONG
�o�O�s���o�ȩ��A�A�i�ݨ�o�ئ��ܦh�H�X�X�J�J�D�b�o��
�A�i�H��J�άO�O���@�U�άO�b�o�ضg��}�D�o�اA�i�H�V�A��
�ͶR�����άO�����D
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "start" : __DIR__"road1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/waiter.c" : 1,
]));
	set("no_fight", 1);
	set("no_clean_up", 0);
set("light",1);

	setup();
	replace_program(ROOM);
}
