// ping.c ���߲~
// �i�H�ΨӨϥ��X�����N�A�X�ϥɸ�
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;
void init()
{
          add_action("do_qufeng","qufeng");
}

void create()
{
        set_name("���߲~", ({ "fengjiang ping", "ping" }) );
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        set("value", 0);
        set("jian",5) ;
        set("material", "��");
        set("long", "�o�O�@�ӥΤW�j�����J�����p�~�A�٥��޶}�~��A�N�i�H�D��\n"
                    "�@�ѿ@���������A�i�H�Ψ��X���C\n") ;
        }
        setup();
}

int do_qufeng(string arg)
{
    object me, obj;
    int myexp , objexp ;
    int mylev , objlev ;
    int myforce , obforce ;
    int steps ;

        me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("�o���T��Ԥ�C\n");
        if( !arg )
                return notify_fail("�A�Q�X�������֡H\n");

        if( this_object()->query("jian") <=0)
                return notify_fail("�p�~�����ɸ��e�w�g���Υ��F�C\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("�o���S���o�ӤH�C\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�ݲM���@�I�A���}���O�����C\n");

        if(obj == me)
                return notify_fail("�ɸ���������A�C\n");

        myexp =  me -> query ("combat_exp" ) ;
        objexp = obj -> query ("combat_exp" ) ;
        mylev =  me -> query_skill("qufeng" ) ;
        objlev = obj -> query_skill("qufeng" ) ;
        myforce =  me -> query_skill("force" ) ;
        obforce = obj -> query_skill("force" ) ;

        if ( mylev <= 0 )
                return notify_fail("�A���|�X�����N�A�����X�ϥɸ����A�����ĤH�I\n");

        myexp = 30 * objexp / myexp ;
        if ( myexp < 30 ) myexp = 30 ;

        if ((int) me ->query("jing") < myexp )
                return notify_fail("�A���뤣���H�X�ʥɸ��˼ġI\n");

        if ((myforce + 15) <= obforce)
                return notify_fail("��⪺���\\�Ӳ`�p�F�A�X���N��L���_�@�ΡI\n");

        this_object()->add("jian", -1);
        steps = ( mylev - objlev ) / 10  ;
        if ( steps < 2 ) steps = 2 ;
        if ( steps > 6 ) steps = 6 ;
        message_vision(HIY "\n$N�޶}�ɲ~��A�⮸�ɲ~��B���O�A�ϱo�~�������𻷻��ƤF�}�h�A\n"
                   "��M��䤧�n�j�@�A�����D�q�������Ӥ@�j�s�ɸ��A�V$n��F�L�h�C\n" NOR,
                   me, obj);
        me -> start_busy (3) ;

        if( userp(obj) )
        {       obj -> fight_ob(me) ;
                me->fight_ob(obj);
        }
        else
        {       obj->kill_ob(me);
                me->fight_ob(obj);
        }
        if (  random ( mylev ) < objlev *2 / 3 )
                message_vision(YEL "\n��$n���B�@�S�A�ɸ����Gť���F���O�A�����פF�}�h�C\n" NOR, me, obj);
        else
        {
         tell_object (obj , HIR "\n�A�P��b�����ɬO�ɸ���¶�A�@�u�u�ɸ������Ȧ��a�V�A\n"
               "���F�L�ӡA�A�uı�o�I�߷L�L�@�h�A�w�Q�ɸ������I\n" NOR  ) ;
         obj -> receive_damage ("jing", steps * 5 ) ;
         obj -> receive_damage ("qi", steps * 6 ) ;
         obj -> start_busy (3) ;
         me -> start_busy (1) ;
        }
        me -> receive_damage ("jing" , myexp ) ;
        return 1;
}
