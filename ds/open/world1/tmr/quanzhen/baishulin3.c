// baishulin3.c �f��L
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�f��L");
        set("long", @LONG
�A���i�F�f��L���`�B�A�}�U��۫p�p�������A�P�P�n�n�C�o��
�����u�D�`���t�A�A�X�G���򳣬ݤ��M�F�C��M�@�u�Q���q�A���e��
��K�W�r�a���F�L�h�A�~�F�A�@���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"cuipingfeng",
                "east" : __DIR__"baishulin4",
                "southdown" : __DIR__"baishulin1",
        ]));
        set("objects", ([
		"/clone/medicine/vegetable/sanqi" : random(2),
        ]));
	set("coor/x", -3140);
	set("coor/y", 40);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}