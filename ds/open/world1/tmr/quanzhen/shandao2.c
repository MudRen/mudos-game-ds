// /d/quanzhen/shandao2.c
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
                "southup"   : __DIR__"shandao1",
                "northdown" : __DIR__"shulin4",
        ]));

	set("coor/x", -3190);
	set("coor/y", 130);
	set("coor/z", 120);
	setup();
        replace_program(ROOM);
}
