// Room: /open/world1/tmr/unquiet_manor/grave2.c

inherit ROOM;

void create()
{
	set("short", "��ֹӫ�");
	set("long", @LONG
�A���B�b�@�B�ӫǤ��A�|�����O������A�ӫǤ��������Q������ç�
�A�ӥޫͮ�X�ʦ~�����y�ʡA�A�u�l�J�X�f�N�wı�o�Y�����ȡA�u�Q�n��
�����}�o�Ӧa��C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"map_14_12",
]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/grove-ghost" : 4,
  __DIR__"npc/moon-tiger" : 1,
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
