#include <ansi.h>
#include <skill.h>

inherit ITEM;

void create()
{
        set_name("�ȱ�",({ "note" }) );
        if(!clonep() ) {
        set("long",@LONG
    �o�O�@�i���L�ڴx�j���ȱ��A���W�Y���G�K�K�X�X�a�g���X��r�A�u
�O�r������A�ڥ��ݤ��M���C

�������O�Gblooding , check�C
LONG
        );
                set("value",0);
                  set("no_give",1);
                set("unit","�@�i");
        }
        setup();
}

void init()
{
        set("no_get",1);
       add_action("do_blood","blooding");
        add_action("do_check","check");
}

int do_check(string arg)
{
        object me;
        me = this_player();
          tell_object( me , "�o�W�����F��A�A���p�j�����F" + me->query_temp("wire-nina-exp")*100/20000 + "%\n");
        return 1;
}
int do_blood(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg!="note") return 0;
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�S���Ű��o�ʧ@�C\n");
        if( me->query_stat("gin") < 50)
                return notify_fail("�A���믫���١A�L�k���o�بƱ��C\n");
        if( me->query_stat("hp") < 50)
                return notify_fail("�A���ͩR���M�A�L�k���o�ئM�I���ʧ@�C\n");
        message_vision(HIR "$N�@�r����A�n�ɫ_�X�@�\�A��A$N�C�C�N�A��w�b�ȱ��W...\n" NOR ,me);
        if( me->query_skill("literate") >= 10 ) {
                /* ��-�u�ʩ��O �ޯ�g��*/
                tell_object(me, CYN "(�A�ݨ�Q�A���٨쪺������ܥX�X�Ӧr�A�A�����D���aŪ��...)\n" NOR );
                me->add_temp("wire-nina-exp" , 1 + random(me->query_attr("int")) );
                me->improve_skill("psychical",1+random(3) );
        } else {
                // Ū����
                tell_object(me, CYN "(�A�ݨ�Q�A���٨쪺������ܥX�X�Ӧr�A���A�������Ѧr�A�L�kŪ�X�N��C)\n" NOR );
        }
        // �믫��10
        me->consume_stat("gin",10);
        // �ͩR��10
        me->consume_stat("hp",10);
        me->start_busy(1);
          if( me->query_temp("wire-nina-exp") >= 20000 ) { // �G�U
        tell_object(me , CYN "�A���W���ȱ��ѩ�L���áA�w�g�}�ꤣ���A�L�k�A�~��ϥΤF..\n" NOR);
                me->delete_temp( "wire-nina-exp" );
                if( me->query_learn("wire nina") 
                ||  me->query("skills_point")+3 > SKILL_MAX_POINT ) {
                        tell_object(me , CYN "�Aı�o����Ƴ��S���o��...\n" NOR);
                } else {
                        // ok ...�Ǩ� �u���ܤ�
                        me->add("skills_point",3);
                        tell_object(me , HIG"(�A���ޯ�ǲ��I�ƪᱼ�T�I�C)\n" NOR);
                        me->improve_skill("wire nina",201);
                }
                destruct( this_object() );
        }
        return 1;
}

