// heifengdong.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�»�}");
        set("long", @LONG
���B���׫n�s�ߪF�����Ӷ��s�W�C�u���s�p���W���U�A���M��
�몺�~�k�A�u�s�y�W���@�ӽV�L�l�ʪ��۬}�A���ɫ_�X�@�Ѷ®�A��
�i�Ȫ��C����O�@����L�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"  : __DIR__"shulin3",
        ]));

	set("coor/x", -3160);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
        replace_program(ROOM);
}
