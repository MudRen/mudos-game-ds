// shandao1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s�D");
        set("long", @LONG
���q�s���O�u�ۮk���Ӷ}�w�X�Ӫ��A�S�O�T������C���ɮk����
�������K�s�z�A�����ӹL�C�ר��s��j�ӮɡA��ݯS�O�p�ߡA���M
�@�����A�N�n���i�U�V�`�W�F�C���F�n�O�@���s�j���Ŧa�C���_�U�q
����s�}�A�����i�H�樣�@�Ӹ��j����C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southeast"   : __DIR__"shanlu13",
                "northdown"   : __DIR__"shandao2",
        ]));

	set("coor/x", -3190);
	set("coor/y", 120);
	set("coor/z", 130);
	setup();
        replace_program(ROOM);
}
