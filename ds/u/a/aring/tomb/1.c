// Room: /u/a/aring/tomb/1.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�Ъd��");
	set("long", @LONG
�o�̬O�j�Ӷ餤���@���d�ڤp���A��ǳ��O�X�өM����A�Q�~��
�ɦa�q�Ť����U�Ӱ��b�ӸO�W�A�Ů𤤰g���۲H�H���G��C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"2.c",
  "southwest" : __DIR__"6.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
