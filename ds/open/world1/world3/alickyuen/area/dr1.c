// Room: /u/a/alickyuen/area/dr1.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�IDoor");
	set("long", @LONG
�o�ثK�OSAINT��|�������A�A�ݨ������ֱ��@���b�X�J�A����ȤH��
�S���_����˪̩�i��|�A��b�D�`���L�C�ݨӦb�Y�B�o�ͤF�@���Y�����a
�סC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dr2",
  "east" : __DIR__"rd2",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
