// mishi6.c �K��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�K��");
	set("long", @LONG
�o���O�j�Ӥ����K�ǡA�|�P�K���z���A�A�u��ɵ��٤W���t���O��
�ӫj�j�����V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X���ƬO�����A�A
���H�q����X�@���_�ءC�٤W�n�H�J���@�ǯB�J�C
LONG	);
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"north" : __DIR__"mishi3",
		"south" : __DIR__"mishi7",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3100);
	set("coor/y", 20);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
