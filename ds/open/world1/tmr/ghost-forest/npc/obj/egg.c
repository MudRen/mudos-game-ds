#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("����J",({"chisel egg","egg"}));
        set("long",@long
�@���j�������H�Y�򪺳��J�A���G������  ����ҥ͡A��߰�w���K
�A�ǻD�H�j�q�H��(blooding)��O���´���a�����C
long
                );
        set_weight(3000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
        set("value",100);
                set("blood",0);
        }
        setup();
}

void init()
{
        add_action("do_blooding","blooding");
}

int do_blooding()
{
        object me,ob,powder;
        me=this_player();
        ob=this_object();

        if(me->is_busy() || me->is_fightint() )
                return notify_fail("�A�����ۡA�S�Ű���L�ơC\n");
        if(me->query("hp") < 20 ) 
                return notify_fail("�̧A�ثe�����A�A�O�L�k�A���媺�C\n");
        message_vision(HIR "$N�r�@�r�ޡA�R�F�X�f�A��b�@���J�W�C\n"NOR ,me);
        ob->add("blood",1);
        set("long",
"�@���j�������H�Y�򪺳��J�A���G������  ����ҥ͡A�ǻD�ݥH�j�q\n"
"�H������(blooding)�A����ơC�W�Y�g��"+(string)ob->query("blood")+"�I�崳�C\n"
                );

        me->receive_damage("hp",9+random(5) );
        me->start_busy(2);

         if(ob->query("blood") > 30)
        {
         message_vision("�u�R�v�a�@�n�A$N���W���@�����J�����a�ܦ��@�ί����C\n",me);
        powder=new(__DIR__"powder");
        powder->move(me);
        destruct(ob);
        }
        return 1;
}

