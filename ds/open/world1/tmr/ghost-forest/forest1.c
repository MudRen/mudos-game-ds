// Room: /open/world1/tmr/ghost-forest/forest1.c

inherit ROOM;

void create()
{
	set("short", "�L���p��");
	set("long", @LONG
�A�����b�L�����@���p���A���n�����B�i�X�˪L��ɿ������C�դ���
�ɥiť��@���λﳾ�s�A�O���@�f�M�դ��N�C���_��h�A��찪�q�s�K�A
�����˴ˡA�F�L�H�ϡA�s��a�[�����Ҥ]�����A���_���C
LONG
	);
	set("world", "past");
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"forest2",
  "southwest" : "/open/world1/tmr/area/river_road",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
