// Modify with AreaMaker1.0
// Room47.c

inherit ROOM;

void create()
{
	set("short","������");
	set("long", @LONG
�o�̪������O�Ѽ��㪺�d�g�ҾQ���A�D����Ǫ�����o���õL��
�C�a���W����U���U���C�A�A�J�Ӥ@�@�A�_��a�թ��W�װ~�A�ɦղ�
ť�ϩ��٥iť��@�}�}�����n�C
LONG
	);
	set("exits", ([
		"north": __DIR__"room37",
		"east": __DIR__"room48",
		"west": __DIR__"room46",
	]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

