inherit ROOM;

void create()
{
	set("short", "��ջ�ئ");
	set("long", @LONG
�o�̦��@����T�H�����J���A�ۻ��ݮݦp�͡A����۫¡C�����
�F���۸O�A�W���g�ۡG�y�s�ؤѡz�A�ݨӳo�L�J���N�O�@�@�|�Ѥ���
���s�ؤѤF�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"west" : __DIR__"cir15",
	]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("objects", ([
  		__DIR__"obj/west_sky_statue" : 1,
	]));

	setup();
	replace_program(ROOM);
}
