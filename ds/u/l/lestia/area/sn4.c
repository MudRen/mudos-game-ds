// Room: /u/l/lestia/area/sn4.c

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
	set("world", "undefine");
set("no_map",1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"sn5",
  "east" : __DIR__"sn5",
  "north" : __DIR__"sn3",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
