// baishulin4.c �f��L
// Winder Oct.10 1998

inherit ROOM;
int do_kan(string arg);

void create()
{
        set("short", "�f��L");
        set("long", @LONG
�o�̬O��L����t�A���u�G���h�F�C�ѤѪ��f��]�}���F�ܦh�C
���䦳�@�O���(frutex)���͡C���A���e�A�N�O�a�V�F�C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "west" : __DIR__"baishulin3",
                "southdown" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
        set("count",1);
        set("item_desc", ([
            "frutex": "�@�O�A�s���X�W�r�����A�䤤�����۫ܦh�p��C\n"
        ]) );

	set("coor/x", -3130);
	set("coor/y", 40);
	set("coor/z", 40);
	setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me=this_player();
        object weapon;
        object ob;

        if( !arg || arg != "frutex" ) {
                return notify_fail("�A�n�夰��H\n");
        }

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("���γå뮣�Ȥ���a�I\n");

        if (query("count")>0) {
        message_vision("$N�ޥX�L�b�A��������O��e�@�}�ì�A�⭱�e�@���q�ߪ����\n",me);
        message_vision("��˥H��A$N�oı�U���ͪ��ۤ@�ʤ���p��A��O����ޤF�_�ӡA\n", me);
        message_vision("�S�Q��o�F��U���s�ۦn�j�@���ڲ��C\n",me);
        add("count",-1);
        ob=new("/clone/medicine/vegetable/fuling");
        ob->move(me);
        }
        else {
        message_vision("$N�ޥX�L�b�A��������O��e�@�}�ì�A�⭱�e�@���q�ߪ����\n",me);
        message_vision("��ˤF�C$N�֪�����C\n", me);
        }

        return 1;
}