// Room: /u/k/king/area/46.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m������");
	set("long", @LONG
�o�̬O�԰�ӳ������ݸ��|�A��B�����O�͡A�Q���@�j��A���㪺��
�~�����ơA�n���H�ɳ��|�����h�q���̶]�X�ӧ����A�A�̦n�٬O�p�߬�
�W���A���M�ܮe����������C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"47",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
