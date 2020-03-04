// Room: /u/l/lestia/area/sn8.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L");
	set("long", @LONG

�R�I���˪L�̨õL���󲧼ˡA���o�X�_�����R����o���M�`�A���I���L
�̳s��������F�y�ʡA��������H�v�ΰʪ����ܸ����o���������A�A�w�Q
�o�I������^�������t�I�L�k�ݮ��A�p�����A�u�Q�֨B���h�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
set("objects", ([ 
__DIR__"npc/bear":2,
]));

	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"sn9",
  "up" : __DIR__"sn7",
]));
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}