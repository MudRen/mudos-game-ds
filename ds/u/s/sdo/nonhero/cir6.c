inherit ROOM;

void create()
{
	set("short", "�_����c");
	set("long", @LONG
�o�̦��@����T�H�����J���A�ۻ��ݮݦp�͡A����۫¡C�����
�F���۸O�A�W���g�ۡG�y�h�D�ѡz�A�ݨӳo�L�J���N�O�@�@�|�Ѥ���
���h�D�ѤF�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"cir5",
	]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("objects", ([
  		__DIR__"obj/north_sky_statue" : 1,
	]));

	setup();
	replace_program(ROOM);
}
