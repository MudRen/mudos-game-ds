// Room: /d/xiangyang/guofuwoshi.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�׫�");
	set("long", @LONG
�o�̴N�O���t�M���T���׫ǡC�Τl�̪����]��²��C����
���䦳�@�i�n�ɡC�ɤW���Q�ȳQ�|�o�������C���Y���諸�a
���\�ۤ@�i�ާ��x�C��W�\�ۤ@�ӥ��G������A������䪺��
�~�̡A���@���ʦX��A���b���o�X�H�H���խ��C�����ۨ�i
��ȡA�����O�@���L�A�W���\�ۤ@�֤s����C
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"guofuhuayuan",
	]));
	set("coor/x", -510);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}