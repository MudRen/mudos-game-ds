// Room: /d/gumu/xuanya.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>;
inherit ROOM;

// �P�H�C�R
void open_sword2() {
        "/adm/daemons/event/gumu.c"->trigger_event();
}
void open_sword() {
        call_out("open_sword2", 60+random(30));
}

void create()
{
        set("short", HIM"�a�V"NOR);
        set("long", @LONG
���B�w�O�׫n�s�����A�e�Y�O�@�j�����ƪ��۾��A�U���h�O����
�j�����U�V�`�V(cliff)�A�ǻD�����ӥj�ӧ̤l�]�����F�j�Ӥ��M�W
����A�q���B�@�D�ӤU�A�F�o�@�͡C���a�V�䦳�ʼ��Ѥj��(tree)�A
�K�������A�p�j�ʤ@�i�B�����ꤧ�a�C
LONG    );
        set("outdoors","forest");
        set("exits", ([
                "west" : __DIR__"mumen",
        ]));
        set("item_desc", ([
                "cliff" : "�a�V�U�@������·¶�C���U�h���O���h�L�^�C\n",
                "tree"   : "�@�ʰ��j������A�W���d�U���g�Q�H�n�̪�����C\n", 
        ]));
        set("no_clean_up", 0);


        setup();
}

void init()
{
        object room, me = this_player();

                 add_action("do_climb", "climb");
        if (random(me->query("int")) <= 15 )
        {
                if(!( room = find_object(__DIR__"tree")))
                        room = load_object(__DIR__"tree");
                if(!(present("du mang", room))) return;
                message_vision(HIR "��M�D��@�Ѹ{�䤧��A�j��W���a�U�@���J�f�ʲӪ��T���Y�����A��$N�����F�C\n\n"NOR, me);
                me->move(__DIR__"tree");
                me->start_busy(3);
        }
}


int do_climb(string arg)
{ 
        object me = this_player(); 

        if (arg == "tree")
        {
                message_vision(YEL"$N�˨����j��W���h�C\n"NOR, me);
                if (me->query_skill("dodge", 1) < 30)
                {
                        message_vision(HIR"���G$N�q��W�@�ӵ��汼�U�ӡC\n"NOR, me);
                        me->receive_wound("hp", random(5) + 5);
                        return 1;
                }
                message_vision(HIY"$N�ܧ֮����b�@���K�����C\n"NOR, me);
                me->move(__DIR__"tree");
                return 1;
        }
        return notify_fail("�A�Q�������H\n");
}

