// shijie2.c �۶�
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
                "southeast" : __DIR__"shijie3",
                "southdown" : __DIR__"shijie1",
        ]));

        //set("objects",([
        //      __DIR__"npc/youke" : 1,
        //      __DIR__"npc/xiangke" : 2,
        //]));
        set("no_clean_up", 0);
	set("coor/x", -3170);
	set("coor/y", 130);
	set("coor/z", 140);
	setup();
        replace_program(ROOM);
}