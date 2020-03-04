// Room: /open/world1/tmr/north_bar/town22e.c

inherit ROOM;

void create()
{
	set("short", "�_�Z���Юѩ�");
	set("long", @LONG
�o�̬O�_�Z�������a���@���ѩСA�Ǩ�����Ƥj���d�A
���C�F�U���U�˪����y�A�]�A�Ѥ�a�z�B���z�N�Ƶ��g��
�W�ѡC�Ǥ����\�F�Q�ӱi�p�Ȥl�A�������i�H��K�a�b�o
Ū�ѩάO�}�|�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"town22",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/nie" : 1,
]));
	set("no_clean_up", 0);
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
