inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�q��W�����y�}�M�~�֡A�ܩ���o�̬O�@���y��H�a�C��W�٦�
�ۤ��֪��ʪ��Х��A�@�@�ӬݡA�����������Y�B�\�֡A���M�s�����Y
���Х������A�i�H�Q���o���y�H���޳N���A�i�O�y�}���ݰ_�Ӧn
�����@�q�ɶ����S���H�ϥΪ��Pı�C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  		"south" : __DIR__"burg4",
	]));
	set("objects",([
		__DIR__"npc/leion.c":1,
	]));

	setup();
	replace_program(ROOM);
}
