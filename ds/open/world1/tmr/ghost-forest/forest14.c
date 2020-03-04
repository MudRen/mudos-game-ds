// Room: /tmr/garea/forest14.c

inherit ROOM;

void create()
{
	set("short", "��h�p��");
	set("long", @LONG
�A�����b�@���d�פp���A���ɶǨӴc�����D���h��A��ܤO�y�C���H
�A�u�Ȧ��w���g���`�C���n�����B�i�ݨ�@�B�`��⪺�h�A�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southwest" : __DIR__"forest12",
	  "northeast" : __DIR__"forest16",
	]));
	set("outdoors", "forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
