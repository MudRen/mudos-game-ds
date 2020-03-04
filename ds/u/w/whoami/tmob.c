#include <ansi.h>
inherit NPC; 
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
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
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
    message_vision("\n\t"HIW"$N�@�ѧ@��I�N"HIB"���l"HIW"�@���ɤJ�C���A�ϥX�e���s�ޡy"HIC"���P�Ѿ�"HIW"�z\n\n"NOR,me,target);
    for(i=0;i<20;i++)
    { 
      call_other(__FILE__, "query_action");
    }
    target->receive_damage("hp",sum_damage*7,me); 
    message_vision(me,HIR"("+damage+")\n"NOR); 
    COMBAT_D->report_status(target);
    target->start_busy(random(3)); 
    return 0;}

