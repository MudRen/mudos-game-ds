// xiaolu12.c ��s�p��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��s�p��");
        set("long", @LONG
�o�̬O��s�W���p���C�o���p���n�����O�H�u��N�ץX�Ӫ��A
�]�\�u�O�H�e�����ĤH��h�F�A�{�X�o�ˤ@���p���ӡC����o�̡A
�A�n���g���F�C
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
                "north" : __DIR__"xiaolu10",
                "south" : __FILE__,
                "enter" : __DIR__"shandong",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2670);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}