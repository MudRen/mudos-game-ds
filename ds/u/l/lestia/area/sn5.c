// Room: /u/l/lestia/area/sn5.c

inherit ROOM;

void create()
{
 set("short", "�_��j�˪L");
	set("long", @LONG

�A���b�@��������𪺪L�l�̡A���Y�ݨ����O�@�K���K���A�C�Y�ݨ쪺
�O�a�֤@��p�p�������C�����Ѷ�����A�ϩ��ɧǶi�J��u�A���P���R�p��
�A�A�λ��֪��B��e�i�A���ԥΤO��񸨸��A�`�ȵo�X�n�Q�A�ϭ����p����
��}�H�����C

LONG
	);
	set("no_clean_up", 0);
	set("current_light", 3);
set("no_map",1);
	set("exits", ([ /* sizeof() == 5 */
  "down" : __DIR__"sn6",
  "east" : __DIR__"sn4",
  "north" : __DIR__"sn5",
  "south" : __DIR__"sn5",
  "west" : __DIR__"sn5",
]));
	set("world", "undefine");

	setup();
	replace_program(ROOM);
}
