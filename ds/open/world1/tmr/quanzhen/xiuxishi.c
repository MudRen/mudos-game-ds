// xiuxishi.c �𮧫�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�𮧫�");
        set("long", @LONG
�o�O���ܤj���ж��A���u�D�`���t�C�и̨S������O���F��A
�u��������ۤ@�i���B�o�εΪA�A���j�ɡA�ɤW���Q�Ȥ]��z�o
�����A�ݵ۴N���H�Q��ı�C
LONG
        );

        set("exits", ([
                "west" : __DIR__"wuchang2",
                "northwest" : __DIR__"wuchang1",
                "south" : __DIR__"shantang",
        ]));
        set("no_clean_up", 0);
        set("sleep_room",1);
        set("no_beg",1);
        set("no_fight",1);
        set("no_steal",1);

	set("coor/x", -2740);
	set("coor/y", 90);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}