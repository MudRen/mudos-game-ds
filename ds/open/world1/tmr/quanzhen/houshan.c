// houshan.c ��s
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��s");
        set("long", @LONG
�o�̤w�g�X�F�����c�A��F�׫n�s����s�C�o�̳��y�᭻�A
�Ů�M�s�A�s�դ]���w�o�h�F�C
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "west" : __DIR__"jingxiushi",
                "northeast" : __DIR__"xiaolu1",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2720);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}