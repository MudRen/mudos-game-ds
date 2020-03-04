#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
        set("short", "��@�q��"HIC"�����ѲP"NOR);
        set("long", @LONG
�o�̬O�@�_�V�A�Z�����������ʤذ��A�V�U�O���½�˪�������
���j�y�U���G�ۡA�j�l���������A�n�n�̮����H��í�A�@�i�i������
���V���Φ��R�Ѫ�����A�i�פѵM�_���A�p�G�b�o��j�������ܡA��
���w�i�H�Ǩ�j���C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "out" : __DIR__"room44",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("no_auc", 1);
        setup();
}

void init()
{
        add_action("do_bugle","bugle");
}

int do_bugle(string str)
{
        object me,z,ob;
        me=this_player();

        if(!objectp(z=present("horn bugle",me) ) )
        return notify_fail("�A�n�j����H \n");

        // 1/13 �s�W by ksj
        ob=find_living("_NPC_LEVIATHAN_");
        if( objectp(ob) )
        {
          if(!environment(ob) )
          {
            destruct(ob);
          }
          else
          {
            message_vision("$N�|�_�����ΤO���j�T�A����㪺�n�T���F�ѻڡC\n",me);
            return 1;
          }
        }
 
        destruct(z);
        message_vision(
        HIW"\n$N�|�_�����ΤO���j�T�A����㪺�n�T���F�ѻڡA�z�A�s�������j���F�C\n"NOR
        HIC"\n��M�����@�D���j���¼v���t����A�@�����j�����v�q�����B�{�I\n\n"NOR,me);
        message("world:world1:vision",
        HIR"\n\t"HIG" ��@�q "HIR"����V�Ǩ��T�G�������n�A�H��@�D����ŧ�V"HIC"�����ѲP"HIR"�I�I\n\n"NOR
        ,users());
        me->add_busy(1);
        new(__DIR__"npc/leviathan")->move(environment(me));
        return 1;
}
