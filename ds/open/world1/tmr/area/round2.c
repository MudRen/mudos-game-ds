// Room: /u/t/tmr/area/round2.c

inherit ROOM;

void create()
{
	set("short", "�ʪ��O");
	set("long", @LONG
�o�O����Һة�¤Ѵ�`�����O���A�s�F�ʤءA���ٵ����A�M�ӦW��
�_�c�C���вM���A���u�ժڡF���e�����A���¿@���C���b���B�A����Y��
�F���P�B�٥ɰ��A�d�����ѭ��A�ɾ�F�F����A�����T�T����F���Ī�
���֤�A�ۺh����L���C�����ƭ���]�A�ܻT�v�v�H���F�������Y�A��p
���A�F¸�A�����A�I�󭷥��C
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"round3",
  "north" : __DIR__"round1",
  "south" : __DIR__"round2",
  "east" : __DIR__"round4",
]));
	set("outdoors","land");
	set("no_clean_up", 0);
	set("no_map",1);
	setup();
	replace_program(ROOM);
}
