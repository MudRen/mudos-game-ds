// foyezhang.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "��ݴx");
        set("long", @LONG
�u�����B�ᬰ��D�A�O�@�B�x�|����}�C�|�P�C�P�A�f��¶�A�x
�|���_�����z�̵}�i���A���G�٬O�@�y���p���x�|�C���_�O�@������C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "east"  : __DIR__"shenheyuan",
        ]));

	set("coor/x", -3180);
	set("coor/y", 70);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}