#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

mapping *combat_action = ({
        ([  "action":       "$N�@�ۡu���ުŤߡv�A���ˮ��ƪ���Ψ��t�̧�V$n��$l",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$N���$n��$l�ϥX�u�U�T�ɱˡv�A���Ƶ��۪��±�����A�w�O�`�J�֦׼Ƥ�",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$N�y�W�®�j���A���O�u�������R�v�����ۡA$n�ۦ��w�ɡA���W��$l���V����",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$N���ΰ~�M�[�t�A�ϥX�u�g�ܦ���v���t�����ޡA�ֱ��L�ۡA���a�@����V$n��$l",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$n��$l���a�֦׺�}�A��������ı�N���F$N���u���k���H���v����",
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
                ([
                "damage_type":  "�ˮ`",
                "action":               "$N����$w�M�ĤO���A�V$n��$l",
                "parry":                20,
                "attact_type":  "sou",
              ]),

                ([
                "damage_type":  "����",
                "action":               "$N��$w��$n��$l��h",
                "parry":                20,
                "attact_type":  "sou",
              ]),

                ([
                "damage_type":  "����",
                "action":               "$N����$w�M�ĤO���A�V$n��$l",
                "parry":                20,
                "attact_type":  "sou",
              ]),
                ([
                "damage_type":  "����",
                "action":               "$N��$w�µ�$n��$l�A�N�L�h",
                "parry":                20,
                "attact_type":  "sou",
              ]),
});

/* �۩w�԰��T�� */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void kill_ob(object ob)
{
        object *guard;
        int i;
        if(!ob || ob==this_object()) return;
        ::kill_ob(ob);

                 guard = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(guard);i++) {
                if( !guard[i]->id("_WUJIAN_") ) continue;
                if( guard[i] == this_object() ) continue;
                if( guard[i]->is_killing(ob->id()) ) continue;

                // guard to kill
                guard[i]->kill_ob(ob);
        }
}


void create()
{
        set_name(HIR "������" NOR,({"coffin ghost-king","coffin","king", "_WUJIAN_"}));
        set("gender", "�k��");
        set("long",@LONG
�����ì��T�~�P�����B�����y�B���P�T�ä��@�B�]�C�D�ĤG���x�v�C
LONG
        );

        set("level", 60);
        set("age", 400);
           set("attack_merits","sou");
        set("title", CYN "�T�~�P" NOR);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("sword",100);
        set_temp("apply/damage",200);
        set_temp("apply/armor",300);
        set_temp("apply/shield",300);


        setup();
                carry_object(__DIR__"obj/sadness-pike")->wield();
                carry_object(__DIR__"obj/blood-boots")->wear();
                  carry_object(__DIR__"obj/boton-leggings")->wear();
                carry_object(__DIR__"obj/mercury-lode");
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if(!objectp(who)) return damage;

        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                  if(random(100)<50)
                {
                        this_object()->receive_heal("hp", damage/2);
                        damage = 1;
                        switch(random(4) )
                        {
                        case 0:
                                message_vision(HIY "\n$N"HIY"�ϥX�]�����ޡu�X��æX�ʧΤƮ�v�A$n���������_���F�F����ĪG�C\n" NOR,this_object(),who);
                                break;
                        case 2:
                                message_vision( "\n$N"HIB"�ʰ_�u������j���v�j�k�A$n"HIB"���J�ƥ@�e�����j�c�ڡA�u�ɶ��L�k�^��...\n" NOR,this_object(), who);
                              // who->add_busy(2);
                             who->receive_damage("mp", 300 + random(100) );
                             who->receive_damage("ap", 300 + random(100) );
                                break;
                        default:
                                message_vision( "\n$N"NOR"�ϥX"HIC"�u���]�ﶳ�v"NOR"�A�������N�׶}�o���������F�C\n" NOR,this_object());
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

                message("world:world1:vision",
                        HBK "\n\t�T�~�P���� " HIR"������"HBK" ���ĳQ" +ob->name(1) + HBK"�}�h�u���A�u���ǥѳ̫�@�f�u�𹮭ưk�X�I�I\n\n"+NOR, users() );

        ob->add("popularity", 5);
         tell_object(ob,HIG "(�A��o 5 �I�n��C)\n" NOR);

        ::die();

        return;
}


