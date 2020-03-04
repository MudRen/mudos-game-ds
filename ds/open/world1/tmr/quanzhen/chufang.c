// chufang.c �p��
// Winder Oct.10 1998

inherit ROOM;
int do_kan(string arg);

void create()
{
        set("short", "�p��");
        set("long", @LONG
�o�̬O���u�Ъ��p�СA�Ψ��W��ۤ@�j����u�ʲӪ����A��
���٨S���A�n�C�@����u�D�H���T�ܭW�y�a���b���̡A�ݵۨ����C
��W���ۤ@���P�l(paizi)�A���䥵�ۤ@���M�C
LONG
        );
        set("exits",([
                "west" : __DIR__"shantang",
        ]));
        set("item_desc", ([
            "paizi": "�ۦ����u�H�A�ݹJ�q�u�C\n"
        ]) );
        set_temp("times" , 20);
        set("objects" , ([
                __DIR__"npc/huogong" : 1,
        ]));

	set("coor/x", -2730);
	set("coor/y", 80);
	set("coor/z", 170);
	setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me=this_player();
        object ob;
        if (query_temp("times")==0)
                return notify_fail("���Ѫ����F���F�A���ѦA�ӧa�I\n");

        if (!arg || arg != "��")
                return notify_fail("�O�ì�A�p�߶˵ۦۭӨ�C\n");

        if(present("huogong", environment(me)) && living(present("huogong", environment(me))))
        {
        if ( (int)me->query("jing")<50)
                return notify_fail("�A����O�����F�A�𮧤@�|��A��a�C\n");

        message_vision("$N�z�_��M�A�ݰ_�@�ڮ���A�ĤO��U�h�C\n",me);
	add_temp("times",-1);

        if (random(3)<2) {
                me->receive_damage("jing",20+random(20));
                message_vision("���G$N�ΤO�L�r�A��M�@�U�l�O�b�F��̡C$N�κɦY��
���O����M�ޥX�ӡA�S�L�F�Ӥj�򰫡C\n",me);
        }
        else {
                me->receive_damage("jing",20+random(40));
                ob = new("/clone/money/silver");
                ob->set_amount(10);
                ob->move(me);
                message_vision("���G������n�Q�A����b�C���u�D�H���۹�$N���A�A�u
�@�������r�A�o�O�A���S�ҡC\n",me);
                message_vision("���u�D�H��$N�@�ǻȤl�C\n",me);
        }
        return 1;
        }
        else
                return notify_fail("���󳣤����F�A�A���֥շF�ڡH\n");
}