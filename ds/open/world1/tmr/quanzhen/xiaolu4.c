// xiaolu4.c ��s�p��
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
                "west" : __DIR__"xiaolu3",
                "north" : __FILE__,
                "south" : __DIR__"xiaolu8",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2680);
	set("coor/y", 130);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}