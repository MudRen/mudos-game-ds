// /d/quanzhen/shanlu10.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o�O�@���D�`�T�����檺�s���A�@���d��L�s���W�A�u�~���O��
�����j�f�s�L�A���M�˨q�C�b���B�i����׫n�s������A�u���s�I��
�m�A�s�t���q�A���ֳ����b�K�Y���n�ڰۤ����C���F�U�O����x�C��
��W�O�@���s���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"    : __DIR__"riyueyan",
                "eastdown"  : __DIR__"jinliange",
        ]));

	set("coor/x", -3140);
	set("coor/y", 30);
	set("coor/z", 60);
	setup();
        replace_program(ROOM);
}
