// xiaolu1.c ��s�p��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��s�p��");
        set("long", @LONG
�o�̬O��s�W���p���C�o���p���n�����O�H�u��N�ץX�Ӫ��A
�]�\�u�O�H�e�����ĤH��h�F�A�{�X�o�ˤ@���p���ӡC
LONG
        );
        set("outdoors", "chongyang");
        set("exits", ([
                "northeast" : __DIR__"xiaolu2",
                "southwest" : __DIR__"houshan",
        ]));
        set("no_clean_up", 0);
	set("coor/x", -2710);
	set("coor/y", 120);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}