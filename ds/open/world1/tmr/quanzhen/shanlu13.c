// /d/quanzhen/shanlu13.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�o�O�@���D�`�T�����檺�s���A�@���d��L�s���W�A�u�~���O��
�����j�f�s�L�A���M�˨q�C�b���B�i����׫n�s������A�u���s�I��
�m�A�s�t���q�A���ֳ����b�K�Y���n�ڰۤ����C���_�U�O���x�C��
��W�O�@���s���C���F�O�@���s�j���Ŧa�C����_�q����s�U�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"     : "/d/gumu/shanlu6",
                "northdown"  : __DIR__"caotangsi",
                "northwest"  : __DIR__"shandao1",
                "eastdown"   : __DIR__"daxiaochang",
        ]));

	set("coor/x", -3180);
	set("coor/y", 110);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}
