// Room: /open/world1/tmr/bagi/area/2f/3f-1.c

inherit ROOM;

void create()
{
	set("short", "�K�D");
	set("long", @LONG
�A�����b�@���K���q�������D���A�b�o�̪Ů�n���O�R��@�ˡA��
���S���y�ʪ��񹳡A�e���H���X�@�����F�A�F����G�Ǩӳ��~���n�T�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3f-2",
  "west" : __DIR__"3f",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
