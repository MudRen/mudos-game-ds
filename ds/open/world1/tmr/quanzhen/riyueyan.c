// riyueyan.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��멥");
        set("long", @LONG
�@���L�ӡA�u�����r�r���s����ǡA�ǥ۪L�ߡA�ᬰ�~�H�C�ר�
�O�e�褣���B��������ۡA���䪺�@������G�A�k�䪺�������Ӷ��A
���D�ӥߡA�K�p�@������A�u�d���@���e���@�H�h���p�D�A���H�q
�L�C���F�U�M�_�W�����O�@���d�骺�s���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "eastdown"  : __DIR__"shanlu10",
                "northup"   : __DIR__"shanlu11",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/song" : 1,
        ]));

	set("coor/x", -3150);
	set("coor/y", 30);
	set("coor/z", 70);
	setup();
        replace_program(ROOM);
}
