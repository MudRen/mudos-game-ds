// Room: /u/m/mulder/area/road12.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�A�i��ı�o�b�o�ر`�`���������A�Q���L��D�ҥH�~���o��
�Ъ��X�{�A�i�H�ѵ��A�b�M���P���H��ѩάO�b�o�إ�y�߱o�M
�Ʊ�U��s��̡A�i�b�o�ذݤ@�ݨ�L�����a�b�o�جO��˥ͦs
���N���ݤ���p�Ƥ]�n�Ρu����v�ݤH�D
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
