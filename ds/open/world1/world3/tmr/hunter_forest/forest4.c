// Room: /tmr/future/hunter_forest/forest4.c

inherit ROOM;

void create()
{
	set("short", "�˪L�p��");
	set("long", @LONG
�A�����b�˪L�����@���p���A�ͪ��}�n�����A�ɬO�c�K����K�B��
���A��P�𤧶��A�椬�ĪӡA�B���F�j�b�����Ӯg�U�Ӫ������A�ϱo�o��
�p����o���t�\�h�C�b�A�����䦳���p�|�i�H�q��@�ʤj�ȳs��e�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "west" : __DIR__"forest8",
	  "east" : __DIR__"forest2.c",
	]));
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("world", "future");

	setup();
	replace_program(ROOM);
}
