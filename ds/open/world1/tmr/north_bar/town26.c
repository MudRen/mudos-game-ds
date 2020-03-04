// Room: /open/world1/tmr/north_bar/town26.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���ЫѤl");
	set("long", @LONG
�Ө�o�̡A�A�o�{�e�����a�Z�����A�q�o�̴N�i�H�ݨ����f
���C�Q�K��Z���A�C�@�ⳣ���۰{�{�o���A�ݼˤl���褣�t�A�i
���K�K���\�Ҥ��U�C
LONG
	);
	set("objects", ([ ]));
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"town27",
  "southwest" : __DIR__"town15",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
