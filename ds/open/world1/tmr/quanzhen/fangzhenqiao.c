// fangzhenqiao.c �X�u��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�X�u��");
        set("long", @LONG
��L�۶��A���e�O�@�y���Y�䦨���p�p�����C���W����W�J�s�y
��A�ݮݦp�͡C�o�̪��s�իD�`�~�m�A���U�@�ݡA�a�V���ߡA�}�U��
���ƹL�A�u�������b��ҡC
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "north" : __DIR__"yuzhengong",
                "southdown" : __DIR__"shijie7",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3140);
	set("coor/y", 140);
	set("coor/z", 190);
	setup();
        replace_program(ROOM);
}