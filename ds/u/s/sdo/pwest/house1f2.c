inherit ROOM;

void create()
{
	set("short", "�����a�G��");
	set("long", @LONG
�o�̪����ҫD�`�n�A�|�P�������@�Ф��V�C�q�����X�h�A�M�J
��î�����O�@���A��A�Τ����\�]�]�O�D�`����A�X�G���O��s����
�A�q��B�ȡA��A�ү�ݨ쪺����a�ѡA�����O��y���A���M���O�b
�˪L��A���O�]�ӯS��F�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"down" : __DIR__"house1",
	]));
	set("objects",([
		__DIR__"npc/selina.c":1,
	]));

	setup();
	replace_program(ROOM);
}
