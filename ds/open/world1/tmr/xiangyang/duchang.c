// Room: /d/xiangyang/duchang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
�o�̥��O�����̤j������C�i�O�j�Է�e�A���K�u�x�x��
�ʷn�B�x�����a�A���j�L���w�U�O�����F����C���iù�����j
�|�A�i�H�Q����ɪ��W�ҡA�~�m�}�Ѫ����A�]�����D�b�L�n
�a�D������C
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"east" : __DIR__"southjie2",
	]));
	set("coor/x", -510);
	set("coor/y", -530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
