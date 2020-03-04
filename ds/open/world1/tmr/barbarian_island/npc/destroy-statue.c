/* �j�ƨtsk�G�}�a��
 * -Tmr 2002/05/08
 */
inherit ITEM;
#include <ansi.h>
#include <skill.h>

#define QUEST "barbarian_island/destroy-fist"

void create()
{
        set_name("�}�a���۹�", ({ "destroy statue", "statue" }));
        set_weight(99999);
        if( !clonep() ) {
                set("unit", "��");
                set("value",100);
                set("no_get",1);
                set("container_unit", "�L");
                set("long",@long
    �o�O�@�L�q�W���Z�H�Ҳ������}�a���۹��A�����q����ɭԶ}�l����
�j�a�������A���G���֦��_�S�����O�A���_�H�̧�j�j���}�a�O�A�A�@
���۹������W�U���۷s�¤j�p���P�����A�����O�]���b���o�͹L�԰��A
�٬O���H�I��(collide)�����˥H�P��d�b�W�Y�����Y�C

(�����Ȭ��ѱj�ƨt�S��ޡu�}�a���v���ΡA�p�A���Q�ǲߡA�ФŹ��ոѥ����ȡC)
long
        );
        }
        setup();
}
void init()
{
        add_action("do_collide","collide");
}

int do_collide(string arg)
{
        object me=this_player();
        int cost=5+random(5);
        if(!me || !userp(me) ) return 0;
        if(!arg || arg!="statue") return 0;
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("�A�����ۡA�Х����U���䪺�u�@�a�C\n");
        if( me->query("skills_point")+3>SKILL_MAX_POINT )
                return notify_fail("�A���ޯ��I�Ƥw���A�L�k���\�ѱo�����ȡC\n");
        if( me->query_learn("destroy fist") )
                return notify_fail("�A�w�g�Ǩ�u�}�a���v�F�A�L�k���\�ѱo�����ȡC\n");
         if( me->query_stat("hp") < 10 )
                return notify_fail("�A�{�b�����骬�A���n�A�L�k�Ψ���ļ��۹��C\n");
        switch( random(4) )
        {
                case 0:
                        message_vision(HIR"$N�j�ۤ@�n�A�@�Y�N���۹��W�ĥh�A���G���o�Y�}��y....\n"NOR,me);
                break;
                case 1:
                        message_vision(HIR"$N�r����ھĤO���V�۹��A���G���X�F���ˡA�R�F�X�f�A��....\n"NOR,me);
                break;
                case 2:
        		message_vision(HIR"$N�ϥX�O�𼲦V�۹��A���G�u�س�v�@�n�A���M�O�Ӱ����_�F...\n"NOR,me);
                break;
                case 3:
                        message_vision(HIR"$N�������V�۹��A���o�Y������B�[�[����O���M��..\n"NOR,me);
                break;          
        }
        me->consume_stat("hp",cost);
        me->add_temp(QUEST,1+random(me->query_attr("int")) );
        me->start_busy(1);
        if( me->query_temp(QUEST) > 5000 ) {
                me->delete_temp(QUEST);
                me->improve_skill("destroy fist",100);
                me->add("skills_point",3);
                tell_object(me,
                HIY "�A���M�Ⲥ��u�}�a���v����q�F�I�I\n" NOR
                +HIG"(�A���ޯ�ǲ��I�ƪᱼ�T�I�C)\n" NOR
                );
        }
        return 1;
}

