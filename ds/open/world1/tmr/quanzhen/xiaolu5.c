// xiaolu5.c ��s�p��
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
                "east" : __DIR__"xiaolu9",
                "west" : __FILE__,
                "north" : __DIR__"xiaolu6",
                "south" : __DIR__"xiaolu3",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2690);
	set("coor/y", 140);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}