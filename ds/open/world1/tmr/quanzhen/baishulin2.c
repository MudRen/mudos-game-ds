// baishulin2.c �f��L
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
                "northup" : __DIR__"baishulin4",
                "west" : __DIR__"baishulin1",
        ]));
        set("objects", ([
                __DIR__"npc/yunbao" : 1,
        ]));
	set("coor/x", -3130);
	set("coor/y", 30);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}