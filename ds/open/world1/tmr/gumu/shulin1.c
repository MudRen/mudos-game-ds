// shulin1.c ��L
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�p��L");
        set("long", @LONG
�o�O�@���p��L�A�P�򪺾�쳣�ܰ��C�����ۤ@�ǥs���X�W�r���A
��A���m�}�ɡC�A�����a���Ǿ�߰_�ӡG���|�g���F�a�A���Y���o�ݨ�
��n����G���@���p���A���æb���O�����C
LONG    );
        set("outdoors", "forest");
        set("exits", ([
        "northdown" : __DIR__"shulin0",
        "southwest" : __DIR__"shulin2",
        "east" : "/open/world1/cominging/purple_sun/psin3.c", //  tmr 2006/10/23

        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

