// shijie3.c �۶�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�۶�");
        set("long", @LONG
�o�O�@��������۪O���A�̤s�ӫءA�H�ۤs�ժ�����d�馱��C
�ѩ�s�հ~�F�A���׫سo���۶��ɪ֩w�O�F���p���\�ҡC����o
�̡A�w�g�i�H�ݨ����u�Э����[���Ѩ��F�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northwest" : __DIR__"shijie2",
                "eastup" : __DIR__"shijie4",
        ]));
        set("objects",([
        //      __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));

	set("coor/x", -3160);
	set("coor/y", 120);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}