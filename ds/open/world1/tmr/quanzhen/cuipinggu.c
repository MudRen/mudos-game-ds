// cuipinggu.c �A�̨�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�A�̨�");
        set("long", @LONG
�A�����e�O�@�y�Φp�̭����j�s���A�s���W�{�{�������O��A�@
���ݹL�h�A���O�@���A���C�o�N�O���a�W�s�A�̨����ѨӡC�q�o��
�~��_�W�A�N��F�׫n�s�W���f��L�F�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "northup" : __DIR__"baishulin1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 20);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}