// /d/quanzhen/shanlu8.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o�O�@���D�`�T�����檺�s���A�@���d��L�s���W�A�u�~���O��
�����j�f�s�L�A���M�˨q�C�b���B�i����׫n�s������A�u���s�I��
�m�A�s�t���q�A���n�U�O�@���D���C���_�W���O�@���d�骺�s���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"   : __DIR__"shanlu9",
                "southdown" : __DIR__"shanlu4",
        ]));

	set("coor/x", -3130);
	set("coor/y", 10);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}
