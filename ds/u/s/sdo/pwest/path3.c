inherit ROOM;

void create()
{
	set("short", "�˪L��");
	set("long", @LONG
�o�y�˪L�X�G�N�~���ͮ𽴫k�C�b�Y�W���L�ۭ������U�س����A
�٦����ӱq�}��@«�ӹL�p�ʪ��A���A�Pı��A�o�j�Ѫ��˪L�̵̨M
�R���۬��O�C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  		"southwest" : __DIR__"path2",
  		"northeast" : __DIR__"path4",
	]));

	setup();
	replace_program(ROOM);
}
