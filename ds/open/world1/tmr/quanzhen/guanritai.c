// guanritai.c �[��x
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�[��x");
        set("long", @LONG
�o�̬O�׫n�s�W���[��x�A�������­��N��H�b�o�̭׿v�F�o��
���x�A�Ψ��[¤��X�������C�o�̪��s�իD�`�~�m�A���U�@�ݡA�a�V
���ߡA�}�U�ն��ƹL�A�u�������b��ҡC
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "north" : __DIR__"shijie9",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));
	set("coor/x", -3150);
	set("coor/y", 80);
	set("coor/z", 180);
	setup();
        replace_program(ROOM);
}