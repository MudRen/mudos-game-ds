// baishulin1.c �f��L
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�f��L");
        set("long", @LONG
¶�L�A�̨����s���A���e�O�@���j�f��L�A�Q�O�ѩ�s���צ�F
���u�A�b�s�U���s���W�ڥ��Q����o�̪��f�𳺷|���o��K�o�򰪡C
�A��i�f��L���A�������Q�Y�����𸭾B��F�A�V����L�`�B�A���u
�V�O�շt�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"cuipinggu",
                "northup" : __DIR__"baishulin3",
                "east" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 30);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}