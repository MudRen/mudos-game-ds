// Room: /u/d/darkfool/area1/31.c

inherit ROOM;

void create()
{
	set("short", "��D");
	set("long", @LONG
�o�̬O��W���I���n���@����D�A�A�ݨ�e�誺�D���O���F�V�����L
�h���A��W���W���@���Ϯ��]���G�b�o���񦳸��i�H��i�h�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"32",
  "northwest" : __DIR__"c1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
