// Room: /d/xiangyang/jiangjungate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�N�x���j��");
	set("long", @LONG
�o�O�N�x�����j���A���O�����O�H������ƨ�A�ݤW�h
�K�¤@���A���G�����I���A�W����������o���G�������F�b�j
�������W�����ӧ��ۤ@�Ӱ��j����P�{�A�W�ѡu�N�x���v�T��
�j�r�A�r��S�q�ƶh�A�u�O���Ǽҽk�F�A�Q���O����d�U����
��C�������@��Ѭf�A�ͱo�a�l���ޡA�K���Z�K�C���e�F���
��U�¥ߵۨ�Ӹy�t�j�M�����L�C
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : __DIR__"eastjie1",
		"north" : __DIR__"jiangjunyuan",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -490);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" &&
                objectp(present("song bing", environment(me))))
                                {
                tell_object(this_object(), "���L�ܹD�G����H�x�������u�Ʃ��Ū��I\n");
                return 0;
        }

        return ::valid_leave(me, dir);
}
