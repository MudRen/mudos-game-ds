// Room: /d/xiangyang/guofuyuan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�����j�|");
	set("long", @LONG
�o�̬O�������j�|�A���@���e�諸�եɷӾ��A�W�ѡ���
�߳��ꡨ�|�Ӥj�r�A�a�U�O�@�⪺�C�j�Q�a�A�|�P�ؤF�X�ʤj
��A���X�ӹ��Х��b�|���x���A�_���O���������U,�C
LONG );
        set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"guofugate",
		"north" : __DIR__"guofuting",
	]));
	set("coor/x", -520);
	set("coor/y", -480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}