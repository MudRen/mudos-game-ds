// Room: /u/a/alickyuen/area/dr11.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ILiftdoor");
	set("long", @LONG
�o�̬O�G�Ӫ��_��X�f�A�O�ǰe�����J�f�A�o������ө��Ҧ����h��
�M�D�n���a��A�Ϩ�Ҧ����f�H�A���b�̧֪��ɶ��o��v���A�O��o����
�|�����`�v�O�Ҧ���|�����̧C���@���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dr13",
  "enter" : __DIR__"dr9",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
