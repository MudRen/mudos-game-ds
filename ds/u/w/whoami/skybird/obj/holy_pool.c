#include <ansi2.h>

inherit ITEM;

void create()
{
        set_name(HIC"�ѱ��t�u"NOR, ({ "holy pool","pool" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long",
                "�@�ӿ���L�䪺�ѵM�����A�䤺�����D�O�Ӧ۩�Q�U�j�s\n"
                "���h�˪e����@�A�j�۵M�W�v���ո`�A�H�ܩ�|�P�èS��\n"
                "���󪺤H�u���X�A���]���|�L���ӷ��X�E�������ٶǨӰ}\n"
                "�}�����Ĩ��A�]�O�]���o�y�F�s�����U���ħ��A�H�۷�\n"
                "���}�y�ܦ��A�H��������ҲV�X�Ӧ��A�o��b�O�y���̪�\n"
                "�����ǧ@�E\n");
                set("unit", "��");
                set("value", 0);
        }
        setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        object me=this_player(),ob=this_object();
        int m_hp,m_ap,m_mp;

        m_hp=me->query("max_hp"); 
        m_mp=me->query("max_mp");
        m_ap=me->query("max_ap");

        if( arg != "pool") return notify_fail("�A�n�ܤ���??\n");
        if( me->is_busy()) return notify_fail("�A�٦b���C\n");
        message_vision("$N�Τ�ŤF�@�f�������M���A�@�f���F�U�h�K�K\n",me);
        tell_object(me,HIG"�@�ѷx�x���Pı�q�A���f���Ǩ�F���СA�o�ѷx�x���𮧤S�q���Ьy«������U�B�K�K\n"NOR);
        me->receive_heal("hp",m_hp); 
        me->receive_heal("ap",m_ap);
        me->receive_heal("mp",m_mp);
        me->receive_curing("all",100); 
        me->start_busy(3);
        ob->add_temp("drinking",1);
           if( ob->query_temp("drinking") > 18 ) {
         destruct(ob);
        } 
        return 0;}
