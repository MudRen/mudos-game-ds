// xiaolu11.c ��s�p��
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
                "east"  : __FILE__,
                "west"  : __DIR__"xiaolu10",
                "north" : __FILE__,
                "south" : __FILE__,
        ]));
        set("no_clean_up", 0);

	set("coor/x", -2660);
	set("coor/y", 140);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}
