// shijie8.c �۶�
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
                "northdown" : __DIR__"shijianyan",
                "southup" : __DIR__"shijie9",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));

	set("coor/x", -3150);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}