// Room: /u/f/fanny/workroom.c

inherit ROOM;

void create()
{
	set("short", "�����Ъ���");
	set("long", @LONG
�o�O�����Фu�@���a��A�o�̦��@����мC�A��\�h���~�Ѱs
�o�ӯ����ЬO�Ӱs���a�A�b�����Ъ��f�����n�n��ۥL���u�����Сv
�o�����l�A���G�ٮ���۱o��֪��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "wiz" : "/d/wiz/hall1",
]));
	set("world", "undefine");
    set("no_clean_up", 1);

	setup();
	replace_program(ROOM);
}
