inherit ROOM;

void create()
{
	set("short", "�F����ئ");
	set("long", @LONG
�o�̦��@����T�H�����J���A�ۻ��ݮݦp�͡A����۫¡C�����
�F���۸O�A�W���g�ۡG�y����ѡz�A�ݨӳo�L�J���N�O�@�@�|�Ѥ���
������ѤF�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"east" : __DIR__"cir9",
	]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("objects", ([
  		__DIR__"obj/east_sky_statue" : 1,
	]));

	setup();
	replace_program(ROOM);
}
