#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

mapping *combat_action = ({
        ([  "action":       "�b�Ť��B�{�X�@������A�H���֪��t�ק�V$n��$l",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$n��$l�W��M�B�{�X�@�Ӥ�x�L�A�`�J�֦׼Ƥ�",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$n�}�U�@�Ӥ�í�A���M�ɭP���W��$l���V���Ǫ�����",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$n���M�G�s�@�n�A���M���W$l�ĥX�@������",
                "attact_type":  "sou",
                "damage_type":  "������",
        ]),
        ([  "action":       "$n�����}�Ǩӡu�I�I�v���n�T�A���M�b�j�L�W�B�X�G�Ӵx�L",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
});

/* �۩w�԰��T�� */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void create()
{
        set_name("�p�Ӧ�",({"rulaifo bonze","bonze","rulaifo"}));
        set("gender", "�k��");
        set("long",@LONG
�@�}ģ�������~��h�A�������A�A�L�k�ݲM���p�Ӧ򪺪��ۡC
LONG
        );
        set("level",50);
        set("age",700);
        set("title","�t�z������");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
                set_skill("jingang-finger",100);
        //map_skill("unarmed","jingang-finger");
            set("attitude", "aggressive");
                set_temp("fly",1);
                set_temp("apply/damage",100);
                set_temp("apply/armor",100);
        setup();
        set_living_name("buddha-war-jingang");
                set("default_actions", (: call_other, __FILE__, "query_action" :));
                set("actions", (: call_other, __FILE__, "query_action" :));
                set("combat_exp",500000);
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
        int val;
                object sw;      // �e�������C

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                if(random(100)<30)
                {
                        damage=1;
                        if(objectp(who))
                        {
                                switch(who->query("class1") )
                                {
                                case "�K����":
                                        message_vision(HIC "\n$N��ۯ���u�Y�L�����u���X�A��$n�������@�@��}�C\n" NOR,this_object(),who);
                                        break;
                                case "�e����":
                                        // �����C�����Z��..
                                        if(  objectp( sw=who->query_temp("weapon") ) 
                                                && sw->query("skill_type")=="sword" 
                                                && sw->unequip() ) 
                                        {
                                                message_vision(HIW "\n�p�Ӧ򯪦��X���B���������F$N��W��$n" HIW "�A$N���M�N�����������W��$n�I�I\n" NOR,who,sw);
                                                message_vision(CYN "($N�渨�F��W���Z���F�C)\n" NOR,who,sw);
                                        }
                                        else 
                                                message_vision(HIM "\n$N����|�P�B�X�ƤQ������A�ϱo$n�������L�k�ǽT������$N...\n" NOR,this_object(),who);
                                        break;
                                case "���Z��":
                                        // ���o���Z�u��
                                        //if(who->query_temp("probit/god-fire") )
                                                message_vision(HIB "\n���M���p�H�᭰�{��A$N�|�P���Ů𳺵M�����@�h�B��...\n" NOR,this_object(),who);
                                        //else 
                                        //      message_vision(HIC "\n$N��ۯ���u�Y�L�����u���X�A��$n�������@�@��}�C\n" NOR,this_object(),who);
                                        break;
                                default:
                                        message_vision(HIG "\n$N���v���M�̪Ů����A�@�಴�S���b��L�����W�C\n" NOR,this_object());
                                        break;          
                                }
                        } else {
                                message_vision(HIG "\n$N���v���M�̪Ů����A�@�಴�S���b��L�����W�C\n" NOR,this_object());
                        }
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage,who);
                return damage;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        ob->add("popularity",6);
                tell_object(ob,HIG "(�A���n��W�[���I�F�C)" NOR);
        ::die();

        return;
}

