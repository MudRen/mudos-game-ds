inherit ROOM;

void create()
{
	set("short", "�˪L�~��");
	set("long", @LONG
�A�ݨ��_�䤣���B���۴X���ЫΡA�ݨӤw�g��˪L����t�F�C��
�L�A�ݵۨ���L�ƪ���v�A���T��o���s�j����L�Q�ޡC�����D�o��
�����L�ɪ���L�s���O�p��������C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 2);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"burg1",
  "south" : __DIR__"path4",
]));

	setup();
	replace_program(ROOM);
}
