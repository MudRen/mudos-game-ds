// Room: /d/xiangyang/guofukefang.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ȩ�");
	set("long", @LONG
�o�̬O�����ȤH�̪���B�A���������@�ƥ��СC������
�k����U�O�@�i�ɡA�ɤW���Q�ȳQ�|�o�������C���Y���諸
�a���\�ۤ@�i��l�A�����٩�ۤ@�i�Ȥl�C��W����a��ۤ�
�Х|�_�A�����٩�۴X���ѡC�a�W�\�ۤ@�֨d����A�@���M��
��¶�Ф��C�]�����t�O�����j�^���A�ҥH����W�����ֻ���
�C�~���ӫ��X�L�C
LONG );
	set("no_clean_up", 0);
	set("sleep_room", 1);
	set("exits", ([
		"east" : __DIR__"guofuhuayuan",
	]));
	set("coor/x", -530);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}