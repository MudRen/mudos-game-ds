#include <ansi.h>
inherit NPC;

string *sor_str= ({
"$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v\n"NOR,
"$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v\n"NOR,
"$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i\n",
"$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v\n"NOR,
"$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n�ϥX�@��"HIC"�u"HIW"�N"HIC"�v\n"NOR,
"$N�����@�w�A�N�⤤���C���a�R���C��A�X$n���`�N�ɡA�@�|�ϥX�u���S���s�v�A��$n�ݤf��h\n",
"$N�j�ܤ@�n�A���t�ϥX�u���Ԧ۬١v�A�C�y��$n��W�����j�n�ަӥh\n",
"$N���ߤ@�ѽİʡA��C�ϥX�@�ۡu�p�üC�v�A�N�C���s���������@�멹$n���Y���{�h\n",
"$N���G�K�F�@��A�ϥX�F�@�ۡu�s���K�H�v�A�K�p�s���@���$n���������Ӧp��O�n\n",
"$N�ߤ��@���A�y��@�C�A�ߧY��$n�U�F�@�ۡu����F�v�A�C���K�p�������k�@��\n",
"$N�⾮�@�ۡu�|�c��Ѫ�v�A���۫K�r��$n��W�j�ޡA���ۤS�p�p��@�뻴�X����V$n�V��\n",
"$N�Ƥj���p�A�H�p��¦�A�H�ӷ����ΡA�V$n�s�ϥX�@�ۡu"WHT"�V�P�}��"NOR"�v�A�C���{�{�b$n���e\n",
});


void do_arc() 
{
        object weapon, me, *tar;
        int x=0, q, tar_d, me_d;
        me=this_object();
        tar = me->query_enemy();
        message_vision("\n\t$N����@�X�@���M�H�ŵ깺���X�@�j��"HIC"�u����v"NOR"�C\n"NOR
        HIW"\t��������ͩR�@��M�H�ֱ��L�۪��e�t��V���I�I\n" NOR,me);

        for(q=0;q<sizeof(tar);q++)
        {
                if( !tar[q] ) continue;
                if( !tar[q]->query_temp("weapon") ) continue;
                if( !(weapon=tar[q]->query_temp("weapon")) ) continue;
                if( 20+random((tar_d=tar[q]->query_skill("dodge")+tar[q]->query_dex())*7/12) < random(me_d=me->query_skill("dodge")+me->query_dex())
                && weapon->unequip() ) {
                        message_vision(HIC "\n�u��v"NOR"�a�@�n�T�A�@�D"HIC"����"NOR"���o$N�渨�F�⤤���Z���I�I\n" NOR , tar[q]);
                        tar[q]->start_busy(1);
                        message_vision(HIC"$N���Z���n���Q�誺���뮶�a�F�ֳ\\�I�I\n"NOR, tar[q]);
                        weapon->set_durable((weapon->query_durable() - random (50) ) );
                } else {
                        message_vision(CYN "\n�u��v"NOR"�a�@�n�T�A����@���W$N�⤤���Z���ϦӳQ�_�H�F�I�I\n" NOR, tar[q]);
                }
                x++;
        }
        if( !x ) {
                message_vision("\n�u����v�����F�ư�A�Ʀ��@�}���Ϯ����F�C\n",me);
                return;
        }
        return;

}

int force = (int)(this_player()->query_skill("moon_force")*0.3) + (int)(this_player()->query_skill("force")*0.2);
int p_force = this_player()->query_skill("star-sword")/5;
int b_force = random(this_player()->query_skill("moon_force"))/4;
int spal = ( p_force*p_force + b_force*b_force )/( p_force + b_force );
void star_tain(string a, string arg);

mapping *combat_action = ({
        ([
        "action": "$N�����@�w�A�N�⤤���C���a�R���C��A�X$n���`�N�ɡA�@�|�ϥX�u���S���s�v�A��$n�ݤf��h",
        "damage":       30+force,
        "dodge" :            -15,
        "attack_type":  "bar",
        "damage_type":  "���", 
        ]),         
        ([
        "action": "$N�j�ܤ@�n�A���t�ϥX�u���Ԧ۬١v�A�C�y��$n��W�����j�n�ަӥh",
        "damage":        force*2,
        "dodge" :          -5,
        "attack_type":  "bar",
        "damage_type":  "���", 
        ]),
        ([
        "action": "$N�����믫�A�����k��A��b���j�ߤ����u�𨳳t���^�Ȥ��A\n�@�K�����A$N��C�ϥX�p÷���@�멹$n���W�g���ӥh",
        "damage":               15+force*2,
        "dodge" :               10,
        "attack_type":  "bar",
        "damage_type":  "�@��", 
        ]),
        ([
        "action": "$N���ߤ@�ѽİʡA��C�ϥX�@�ۡu�p�üC�v�A�N�C���s���������@�멹$n���Y���{�h",
        "damage":               10+force*2,
        "dodge" :               -3,
        "attack_type":  "bar",
        "damage_type":  "�ж�", 
        ]),
        ([
        "action": "$N���G�K�F�@��A�ϥX�F�@�ۡu�s���K�H�v\n�A�K�p�s���@���$n���������Ӧp��O�n",
        "damage":               12+force*2,
        "dodge" :               -15,
        "attack_type":  "bar",
        "damage_type":  "���", 
        ]),
        ([
        "action": "$N�ߤ��@���A�y��@�C�A�ߧY��$n�U�F�@�ۡu����F�v�A�C���K�p�������k�@��",
        "damage":               15+force*2,
        "dodge" :               13,
        "attack_type":  "bar",
        "damage_type":  "���", 
        ]),
        ([
        "action": "$N�ϥX�@�ۥ����L�_�����c�C��$n���W�n�ަӥh�A���Ʀb�~�������ܬ��u���s�զ�v�A�ϧ�V$n�U�L",
        "damage":               18+force*2,
        "dodge" :               5,
        "attack_type":  "bar",
        "damage_type":  "���", 
        ]),
        ([
        "action": "$N�⾮�@�ۡu�|�c��Ѫ�v�A���۫K�r��$n��W�j�ޡA���ۤS�p�p��@�뻴�X����V$n�V��",
        "damage":               17+force*2,
        "dodge" :               5,
        "attack_type":  "bar",
        "damage_type":  "�W��", 
        ]),
        ([
        "action": "$N�Ƥj���p�A�H�p��¦�A�H�ӷ����ΡA�V$n�s�ϥX�@�ۡu�V�P�}�ѡv�A�C���{�{�b$n���e",
        "damage":               21+force*2,
        "dodge":                -10,
        "attack_type":  "bar",
        "damage_type":  "�ζ�",
        ]),
        ([
        "action": "$N�}�C�@���A���O��i�C���A�ϥX"HIC"�u"HIR"��"HIC"�v"NOR"�r�Z�A�C�۬������檽���i",
        "damage":       25*2,  
        "attack":       10*2,
        "attact_type":  "bar",  
        "damage_type":  "���", 
        ]),
        ([
        "action": "$N���C��e�C���A���_��C�P�A�h�h�]��$n�A�X����C�@���A�@��"HIC"�u"HIB"�\\"HIC"�v"NOR"�W�V$n��$l",
        "damage":       15*2+random(spal/4),
        "dodge":        -5,
        "delay":        1,
        "attack_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N������i�A��M�b$n���ǹ�$n�X�F�@��"HIC"�u"HIG"��"HIC"�v"NOR,
        "damage":       18*2,
        "delay":        2,
        "attack_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�f�������D�y�I�G�����U�l�A�A�s�����C�V�z�A�⤤���C��M�D�_�g�A�ϤF"HIC"�u"YEL"�U"HIC"�v"NOR,
        "damage":       25*2,
        "delay":        2,
        "attack_type":  "bar",
        "damage_type":  "���",
        ]),
        ([
        "action": "$N�B����u�A��W���C��M���@�T�A����J�ɡA��$n��$l�ϥX�@��"HIC"�u"HIW"�N"HIC"�v"NOR,
        "damage":       30*2,
        "attack_type":  "bar",
        "damage_type":  "���",
        ]),
});

void create()
{
        set_name("�q�x",({"duan hong","duan","hong"}) );
        set("long",@LONG
�e�����C�t�A�����C�t�T������C�D�μC���̰����q�E
LONG);
        set("title",HIW"�e���C�t"NOR); 
        set("nickname","��C�s��");        
        set("age",40+random(5));
        set("level",80);
        set("gender","�k��");
        set("attitude", "peaceful");  
        set_skill("fogseven", 100+random(50)); 
        set_skill("dodge", 100+random(50)); 
        set_skill("unarmed", 100+random(50)); 
        set_skill("sword", 100+random(50)); 
        set_skill("star-sword", 100+random(50));
        set_skill("sorgi_sword", 100+random(50)); 
        set_skill("moon_force", 100+random(50)); 
        set_skill("sorsin_force", 100+random(50));
        set_skill("force", 100+random(50));
        map_skill("dodge","fogseven");
        map_skill("sword","star-sword");
        set("Merits/bar",8+random(10));
        set("int",175);
        set("addition_armor",50+random(100));
        set("Merits/wit",8+random(4));
        set("addition_damage",50+random(100));
        add("apply/hit",80+random(30));
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                (: do_arc :),
                (: command ("exert moon-force shadow") :),
        }));
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
 
int special_attack(object me,object target,int hitchance)
{           
            int sk = me->query_skill("star-sword"),
            force = me->query_skill("force"),
            w_force = me->query_skill("moon_force"),
            sw = me->query_skill("sorgi_sword"),
            target_armor, me_damage, target_dodge, me_dex, sum_damage, g,damage, i;
            object *attack_targets;
            string msg;

                target_armor = target->query_armor();
                target_dodge = target->query_skill("dodge")/3 + random(target->query_dex()/4);
                me_dex = me->query_dex() * 3;
                me_damage = me->query_damage() + w_force/4 + sk/3;
                me_damage = me_damage + random(me_damage/4);
                sum_damage = me_damage - target_armor/2 - random(target_armor/2); 

            switch( random(10) ) {
            case 0:
message_vision("\n$N���C�@�ߡA�N�C�m��ݫe���o�e�A���ۥμC�b�Ť����F�� "NOR+BLU"[��]"NOR" �r�A"
               "\n�j�ܤF�@�n�M�@��"HIC"�y"HIY"���P�Цr"HIC"�z"NOR"���V$n�C\n\n", me, target);
                   target->receive_damage("ap", sum_damage/10, me);
                   target->receive_damage("hp", sum_damage, me);
                   target->start_busy(1+random(3));
                   message_vision(HIR"$n�@�Ӥ��p�ߡA�Q$N�����F���P�Цr�A���G�f���@�}�A��g�Q�I�I"NOR, me, target);
                   me->add_busy(1+random(2)); 
                   if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                   message_vision(HIY" ("+ HIR + sum_damage + HIY")"NOR" \n\n"NOR, me);
                   else message_vision("\n\n", me);
                   COMBAT_D->report_status(target);
                   break;
            case 1:

message_vision("$N�ϤF�Ϥ⤤���C�A�а_"HIW"�޹D����"NOR"�A���۫K�μC�I�V$n���޹D�A"NOR, me, target);
message_vision(HIW"�ϱo$N����ʼu!!\n"NOR, target);

                   if( sk < 30 ) target->start_busy(1+random(2));
                   if( sk > 30 && sk < 60 ) target->start_busy(2+random(2));
                   if( sk > 60 && sk < 90 ) target->start_busy(3+random(3));
                   if( sk >= 90 )
                       {
                        target->receive_damage("hp", me->query_damage()/3, me);
                        target->start_busy(4+random(2));
                        message_vision(HIR"$N���G���F�I�ˡI"NOR, target);
                       }
                   if( me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
                   message_vision(HIY" ("+ HIR + me->query_damage()/3 + HIY")"NOR" \n"NOR, me);
                   else message_vision("\n", me);
                   COMBAT_D->report_status(target);
                   break;
             case 3: 
                    attack_targets = me->query_enemy();message_vision(HIC"\n�u��$N�|�P�~�M�@�ѱj�j����e�t�W�ɡK\n"NOR, me);
message_vision(HIY"�@�@$N���C�a���Ĥ����A�����K$N�o�X�C��A�H�C�g�ġK\n\n"NOR, me);
message_vision(HIM"  $N�ϥX - �i�� "HIY"�y "HIR"�� "HIG"�D "HIR"�P"HIG" �D "HIR"�C "HIG"�D "HIR"�� "HIY"�z "HIM"�СССССССС�\n\n"NOR, me);

                        for(g=0;g<sizeof(attack_targets);g++)
                        {
              if( random( attack_targets[g]->query_dex() ) < random( me->query_dex()*2 ) + 15 ) { 
              if( random( attack_targets[g]->query_skill("force")/2 ) > random(force) )
                        {
                          damage = me->query_damage()*2/3 + w_force/4 + random( me->query_damage()/4 );
                          damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                          attack_targets[g]->receive_damage("hp",damage, me);
                          attack_targets[g]->start_busy(2);
           message_vision(CYN"$N�ĤO����, �w�O���U�F�o�D�C��I"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                          COMBAT_D->report_status(attack_targets[g]);
                        }
                          else
                        {
                          damage = me->query_damage() + w_force*2/3 + random( me->query_damage()/3 );
                          damage = COMBAT_D->Merits_damage(me, target, damage , "bar");
                          attack_targets[g]->receive_damage("hp", damage , me);
                          attack_targets[g]->start_busy(3);
           message_vision(HIC"$N���Ω��, �Q�C�𥴭ӥ��ۡI"HIR" ("HIW+damage+HIR")"NOR,attack_targets[g]);
                          COMBAT_D->report_status(attack_targets[g]);
                        }
                        }
                          else {
           message_vision(YEL"$N���L�F�o�D�C��I\n"NOR,attack_targets[g] );
                          attack_targets[g]->start_busy(1);
                               }
                        }
                        message_vision("\n",me);
                        break;
           case 4:

    message_vision("\n\t"HIW"$N�@�ѧ@��I�N"HIB"���l"HIW"�@���ɤJ�C���A�ϥX�e���s�ޡy"HIC"���P�Ѿ�"HIW"�z\n\n"NOR,me,target);
    for(i=0;i<20;i++)
    {
      msg=sor_str[random(sizeof(sor_str))];
      message_vision(msg,me,target);
    }
    target->receive_damage("hp",sum_damage*3,me); 
    message_vision(HIR"("+sum_damage*3+")\n"NOR,me); 
    COMBAT_D->report_status(target);
    target->start_busy(random(3)); 
            break;
           case 5:
message_vision(
HIC"                      ������"HIR"��������"HIC"������
"HIW"                      �u"NOR" �C "HIW"��  �P  ��  �q          "NOR"�@
                      "CYN"�i"NOR"
                    "CYN"�i�i"HIR"_________________"NOR"
        "RED"�i          "CYN"�i�i                 "HIR"�@_____________"NOR"
      "RED"�i�i�i      ��"CYN"�i�i"HIM"�i�i�i�i�i�i�i�i��              "HIR"�@________________"NOR"
      "RED"���i�i�i�i�i�i"CYN"�i"HIC"��"HIM"������������������"HIG"�i�i�i�i�i�i�i��                "HIR"�@"NOR" 
      "RED"���i"HIY"��"HIW"�i�i�i�i"NOR""CYN"�i"HIC"�i"HIC"��  �P  ��  �C  ��"HIG"����������������"HIB"�����������������~"HIR"�~"NOR"
      "RED"���i�i�i�i�i�i"CYN"�i"HIC"��"HIM"������������������"HIG"�i�i�i�i�i�i�i��"HIR"________________��"NOR" 
      "RED"�i�i�i      ��"CYN"�i�i"HIM"�i�i�i�i�i�i�i�i�� "HIR"_____________��"NOR"
        "RED"�i          "CYN"�i�i"HIR"_________________��"NOR"              
                    "CYN"�i�i"NOR"
                      "CYN"�i"NOR
,target,me);

    target->receive_damage("hp",sum_damage*7,me); 
    message_vision(HIR"\n("+sum_damage*7+")\n"NOR,me); 
    COMBAT_D->report_status(target);
            break;
                   }
                   return 0;
}     

varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if(this_object()->is_fighting() ) {
        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);
                if(random(100)<15)
                {
                   damage/=100000;
                   message_vision(HIC"\n$N����P�򪺮�l�N$n����է������l���F�I�I\n" NOR,this_object(),who);
                }
                }
                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}
