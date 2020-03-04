//buddha war �j�Y�� �p�Ӧ�

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
          set("level", 65);
        set("age",700);
          set("race", "tiger");
        set("title","�t�z������");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
                set_skill("jingang-finger",100);
        //map_skill("unarmed","jingang-finger");
            set("attitude", "aggressive");
                set_temp("fly",1);
        set_temp("apply/damage", 100);
        set_temp("apply/armor", 150);
        set_temp("apply/shield", 150);


        setup();
        set_living_name("buddha-war-jingang");
                set("default_actions", (: call_other, __FILE__, "query_action" :));
                set("actions", (: call_other, __FILE__, "query_action" :));
                  set("combat_exp",2000000);
                carry_object(__DIR__"eq/finger")->wear();
                  carry_object(__DIR__"eq/necklace")->wear();
                    carry_object(__DIR__"eq/gloves")->wear();
                     carry_object(__DIR__"eq/ankle")->wear();



}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
                object sw;      // �e�������C

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                  if(random(100)<50)

                {
                        this_object()->receive_heal("hp",damage/2);
                        damage=1;
                        switch(random(4) )
                        {
                        case 0:
                                message_vision(HIY "\n$N��ۯ���u�Y�L�����u���X�A��$n�������@�@��}�C\n" NOR,this_object(),who);
                                break;
                        case 1:
                                if(  objectp( sw=who->query_temp("weapon") ) && sw->unequip() ) 
                                {
                                        message_vision(HIW "\n�p�Ӧ򯪦��X���B���������F$N��W��$n" HIW "�A$N���M�N�����������W��$n�I�I\n" NOR,who,sw);
                                                message_vision(CYN "($N�渨�F��W���Z���F�C)\n" NOR,who,sw);
                                                break;
                                }
                                message_vision(HIM "\n$N����|�P�B�X�ƤQ������A�ϱo$n�������L�k�ǽT������$N...\n" NOR,this_object(),who);
                                break;
                        case 2:
                                message_vision(HIB "\n���M���p�H�᭰�{��A$N�|�P���Ů𳺵M�����@�h�B��...\n" NOR,who);
                                who->add_busy(3);

                                break;
                        default:
                                message_vision(HIG "\n$N���v���M�̪Ů����A�@�಴�S���b��L�����W�C\n" NOR,this_object());
                        break;          
                                } // end switch
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

        ob->add("popularity",5);
          tell_object(ob,HIG "(�A���n��W�[���I�F�C)\n" NOR);

        if(random(100)<70) {
            // �p�Ӧ�ߡA�i�����A���O����save
            new(__DIR__"obj/heart")->move(ob);
            message_vision("$N�q�p�Ӧ򨭤W���U�@�����ʪ��p�Ӧ�ߡC\n",ob);
        }


        ::die();

        return;
}

