// /d/quanzhen/shanlu9.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o�O�@���D�`�T�����檺�s���A�@���d��L�s���W�A�u�~���O��
�����j�f�s�L�A���M�˨q�C�b���B�i����׫n�s������A�u���s�I��
�m�A�s�t���q�C���_�W���O�����աC���n���O�T�򪺤s���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"jinliange",
                "southdown" : __DIR__"shanlu8",
        ]));

	set("coor/x", -3130);
	set("coor/y", 20);
	set("coor/z", 40);
	setup();
        replace_program(ROOM);
}
