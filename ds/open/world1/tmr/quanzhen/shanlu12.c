// /d/quanzhen/shanlu12.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s�D");
        set("long", @LONG
���q�s���O�u�ۮk���Ӷ}�w�X�Ӫ��A�S�O�T������C���ɮk����
�������K�s�z�A�����ӹL�C�ר��s��j�ӮɡA��ݯS�O�p�ߡA���M
�@�����A�N�n���i�U�V�`�W�F�C���_�O�@���s�j���Ŧa�C���n�U�O�@
�������C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup"    : __DIR__"daxiaochang",
                "southdown"  : __DIR__"juyan",
        ]));

	set("coor/x", -3170);
	set("coor/y", 100);
	set("coor/z", 110);
	setup();
        replace_program(ROOM);
}
