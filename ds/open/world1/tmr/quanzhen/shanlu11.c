// /d/quanzhen/shanlu11.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o�O�@���D�`�T�����檺�s���A�@���d��L�s���W�A�u�~���O��
�����j�f�s�L�A���M�˨q�C�b���B�i����׫n�s������A�u���s�I��
�m�A�s�t���q�A���ֳ����b�K�Y���n�ڰۤ����C���n�U�O����q�Ѧ�
�ߪ����ۡC���_�O�@���c�����s�L�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"    : __DIR__"shulin1",
                "southdown"  : __DIR__"riyueyan",
        ]));

	set("coor/x", -3150);
	set("coor/y", 40);
	set("coor/z", 80);
	setup();
        replace_program(ROOM);
}
