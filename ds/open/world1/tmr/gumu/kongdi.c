// kongdi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�Ŧa");
	set("long", @LONG
�o�O�׫n�s�s�y�B���@���Ŧa�A�a�ե��Z�C�_���@���p�����k�s�z
�ӤW�A�q���O�׫n�s�D�p�C�n��M����@�j���K�L�A�u�D�}�}�^�n�۪L
���ǥX�C���_�O�@���s���C���n�M��U���@���p�|�C
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"west"    : __DIR__"shulin5",
		"south"   : __DIR__"shulin4",
		"northup" : __DIR__"shanlu1",
	]));
	setup();
	replace_program(ROOM);
}
