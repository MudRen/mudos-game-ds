// Room: /tmr/future/hunter_forest/forest3.c

inherit ROOM;

void create()
{
	set("short", "�˪L�p��");
	set("long", @LONG
�A�����b�˪L�����@���p���A����n�����B�A���������i�H�ݨ�˪L
���X�f�Ҧb�C���ۤp�����_���h�A�i�H�ݨ����ۤ@�h�h���H���Q���۪L��
�A���ɥi�Hť���u���v�B�u���v���ʪ��s�n�ǨӡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"forest2",
	  "north" : __DIR__"forest5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
	replace_program(ROOM);
}
