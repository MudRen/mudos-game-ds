// /d/quanzhen/xiaohebian.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�p�e��");
        set("long", @LONG
���B���׫n�s���@�����B�A�u���@���`�a�A����B�ʡA�P���
�O�Ѥѥj��A�����R�����C�����B���p�e�Ѥs�}(dong)����X���u
���ҧΦ��A�F�F�����n�����Aı�o���߶��Z�C���_�i�q���s�L�`�B�C
����i�i�J�s�}���C
LONG
        );
        set("outdoors", "zhongnan");
        set("item_desc", ([
                "dong" : "�@�Ӳ`��B�շt�B���ƪ��p�s�}�C\n",
        ]));
        set("exits", ([
                "enter" : __DIR__"shandong1",
                "north" : __DIR__"shanlu7",
        ]));

	set("coor/x", -3160);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
