// mishi3.c �K��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�K��");
	set("long", @LONG
�o���O�j�Ӥ����K�ǡA�|�P�K���z���A�A�u��ɵ��٤W���t���O��
�ӫj�j�����V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X���ƬO�����A�A
���H�q����X�@���_�ءC�٤W�n�H�J���@�ǹϧΡC
LONG	);
	set("exits", ([
		"west"  : __DIR__"mishi2",
		"east"  : __DIR__"mishi4",
		"north" : __DIR__"mishi5",
		"south" : __DIR__"mishi6",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
