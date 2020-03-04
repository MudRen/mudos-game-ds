// cexiang.c ���[
// Java Oct.10 1998
#include <ansi.h>
        
inherit ROOM;
void back(object me);
void init();
int do_sleep(string arg);

void create()
{
        set("short", "���[");
        set("long", @LONG
�o���O�j�Ӥ������[�СC�ж������©I�I���A����F�賣�S���A�u
���@����÷(rope)�A�b�ǪF���@���K�v�W�t��A��÷��L�Ǥ��A÷�l��
�t�ݨt�b������@�f�v�W�A÷�����a�����@�H�Ӱ��C
LONG );

        set("exits", ([
                "west" : __DIR__"mudao14",
        ]));
        set("item_desc", ([
                "rope" : "�@���ӳ�÷�A�ݨӬO�j�ӧ̤l�̺ίv���ҡC\n"
        ]));
        set("no_clean_up", 0);
        setup();
}

void init()
{
        ::init();
        add_action("do_sleep", "sleep");
}

int do_sleep(string arg)
{
        object room, *ob, me=this_player();
        int i, j;

        if( !(room = find_object(__DIR__"rope")) )
                room = load_object(__DIR__"rope");
        
        if( !arg || arg != "rope" )
        {
                return notify_fail("�A�n�Φb����H\n");
        }
        
        if(me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ű��o��ơC\n");
        
        if((int)me->query_skill("dodge",1) < 10)
        {
                message_vision("$N���򥻻��\\�����_���A�����W÷�h�C\n",me) ;
                return 1;
        }
        me->receive_damage("ap",10+ random(20));
        ob = all_inventory(room);
        j = 0;
        for(i=0; i<sizeof(ob); i++)
                if( living(ob[i]) && ob[i] != me ) j++;
        if (j > 0)
        {
                message_vision("$N�����a�_�A�o�{÷�W���H�A�u�n�����U�a�C\n",me);
                return 1;
        }
        message_vision("$N�����a�_�A���÷�W�A�H÷���ɡA�ΰ_ı�ӡC\n", me);
        me->move(room) ;
        me->start_busy(3);
        call_out("back", 6 , me);
        return 1 ;
}

void back( object me )
{
        int sk;
        me->move(__DIR__"cexiang");
        message_vision("$N�@ı���ӡA�����D�U÷�ӡC\n",me);
        sk=me->query_skill("dodge",1);
        if (sk < 20)
        {
             me->improve_skill("dodge",me->query("int"));
                tell_object(me,HIC "�A���򥻻��\\�i�B�F!\n" NOR);
        }
}

