// jingxiushi.c �R�׫�
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�R�׫�");
        set("long", @LONG
�o�̬O���u�Ч̤l�R�װѮ��D�����ж��A�ж��ܤp�A�����B���F
�F�b�b�A��ȳ��\��o�������A���H�@�ݴN�ߵL�����C
LONG
        );
        set("exits", ([
                "east" : __DIR__"houshan",
                "south" : __DIR__"diziju",
                "west" : __DIR__"houtang3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/liu" : 1,
        ]));

	set("coor/x", -2730);
	set("coor/y", 110);
	set("coor/z", 170);
	setup();
}

int valid_leave(object me, string dir)
{
        mapping fam;

        if (dir == "east" )
        {
                if(!(fam = me->query("family")) || fam["family_name"]!="���u��")
                {
                        if(present("liu chuxuan", environment(me)) && living(present("liu chuxuan", environment(me))))
                        {
                                return notify_fail(
"�B�B�@�����d��A�D�G�᭱�O���Я��v�M�פ��a�A" + RANK_D->query_respect(me) + "��
��B�C\n");
                        }
                        else
                                return ::valid_leave(me, dir);
                }
                else
                        return ::valid_leave(me, dir);
        }
        else
                return ::valid_leave(me, dir);

}