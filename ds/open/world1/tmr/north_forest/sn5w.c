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
	set("exits", ([ /* sizeof() == 5 */
  "south" : __DIR__"sn6w",
  "east" : __DIR__"sn4",
]));
	set("objects", ([ 
	__DIR__"npc/troll2":2,
	__DIR__"npc/troll3":2,
	]));

	setup();
	replace_program(ROOM);
}
