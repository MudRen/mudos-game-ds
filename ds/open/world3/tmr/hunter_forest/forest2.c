// Room: /tmr/future/hunter_forest/forest2.c

inherit ROOM;

void create()
{
	set("short", "�˪L�p��");
	set("long", @LONG
�A�����b���i���˪L���@���p���A���n�N�O�˪L���X�f�A�i�H�^���q
�ϡC�A�ݵۤp����Ǫ��ۯS�������A�j�b���O�A�ͥ��ҨS�����L���A��
�ɤ]�i�H�ݨ������W���p�ʪ�����b�L���C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"forest4",
  "south" : __DIR__"forest1",
  "east" : __DIR__"forest3",
]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
	replace_program(ROOM);
}
