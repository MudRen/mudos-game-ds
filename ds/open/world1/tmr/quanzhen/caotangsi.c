// caotangsi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "���x");
        set("long", @LONG
�o�O�@�y���׫n�s�_�S���p�x�C�x�|�����@�f�j���A�W������
���C�]���C�ѲM�᳣�|���@�ѥ��j�������A�ۤ��̸͸ͤɰ_�A���ֹC
�ȨӦ��A�N�O���F�@�[���_���C���n�W�O�@���T�򪺤s�D�C���_�O�@
�����˴˪��p�|�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southup"     : __DIR__"shanlu13",
//              "north"       : __DIR__"",
        ]));
        set("no_clean_up", 0);

	set("coor/x", -3180);
	set("coor/y", 120);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
