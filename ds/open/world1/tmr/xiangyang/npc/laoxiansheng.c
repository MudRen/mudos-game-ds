// zhu.c ���Q

inherit NPC;
#include <ansi.h>

string ask_buy();
int ask_degree();
void create()
{
        set_name("�ѥ���", ({ "lao xiansheng", "lao", "xiansheng"}));
        set("long",
"�o��ѥ��ʹ����L�����A���L�j�x�A�{�]�~�Ѧ^�Ѯa�����[�i�Ѧ~�A�g
�w���ϧf��w���A�T�ܽСA�b�o�ର�q�~�����ҡC\n");
        set("gender", "�k��");
        set("age", 65);
        set("no_get", 1);
        set_skill("literate", 300);

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/damage", 10);

        set("combat_exp", 4000);
        set("shen_type", 1);
        setup();
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/��"))
                return 0;
        ob->add_temp("mark/��", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        object me = this_player();
        if (!(int)who->query_temp("mark/��"))
                who->set_temp("mark/��", 0);
        if (ob->query("money_id") && ob->value() >= 1000)
        {
                message_vision("�ѥ��ͦP�N���I$N�@��Ū�Ѽg�r�����D�C\n", who);
                who->add_temp("mark/��", ob->value() / 50);
                if( me->query_skill("literate", 1) > 21)
                {
tell_object(me,"�A�{�b�w���@�w����ƪ��ѡA�]�i�H�ۤvŪ�Ѳ`�y�F�C\n");
                        return 1;
                }
                return 1;
        }
}

