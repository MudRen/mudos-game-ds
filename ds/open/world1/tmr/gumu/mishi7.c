// mishi7.c �K��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�K��");
	set("long", @LONG
�o���O�j�Ӥ����K�ǡA�|�P�K���z���A�A�u��ɵ��٤W���t���O��
�ӫj�j�����V�C�٬O�ξ�����C�۬�X�_�Ӫ��A���X���ƬO�����A�A
���H�q����X�@���_�ءC�٤W�n�H�J���@�ǭ��V�C
LONG	);
	set("exits", ([
		"east"  : __DIR__"mishi8",
		"west"  : __FILE__,
		"north" : __DIR__"mishi6",
		"south" : __FILE__,
	]));
	set("no_clean_up", 0);
    set("objects", ([
            __DIR__"npc/girl2" : 1,
    ]));


	setup();
	replace_program(ROOM);
}
