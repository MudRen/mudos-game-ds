#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
    ([ "action": "$N�z�ܤ@�n�A��W�K�禳�p�Q���\\���n�V$n�u"HIM"���s�Q�K��"NOR"�v�K�礣���a½��b�ˡI",
       "damage": 10,
       "dodge" : 8,
       "parry" : 5,
       "attact_type": "bio",  // �]�w�ޯ઺��������
                              // ������ �ͪ�(bio) �~��(bar)
                              // �]�k(wit)���F(sou)���(tec)
       "damage_type": "�����A�Y�w���ȺN���M�F�n��_",
    ]),
    ([ "action": "$N�۹D�G�u"HIG"������I"NOR"�v�q�I�᮳�X�K�ꤣ�����ʦa���V$n��$l�I",
       "damage": 8,
       "dodge": -5,
       "parry": 12,
       "attact_type": "bio",
       "damage_type": "���ˡA����$n���_���P",
    ]),
    ([ "action": "$N�q�h�̺N�X��M�A�ϥX�u"HIB"�O�s��"NOR"�v�ۤƦ��C�C�|�Q�E���M�P�ɼA�V$n��$l�I",
       "damage": 7,
       "dodge" : 9,
       "parry" : -6,
       "attact_type": "bio",
       "damage_type": "�ζ�",
    ]),
    ([ "action": "$N�Ϥⴤ���M�A�q���i�䲧�����׳s��X�۬�V$n$l�A���O�����M�k�u"HIW"�ʤѤ�"NOR"�v",
       "damage": 13,
       "dodge" : 20,
       "parry" : -15,
       "attact_type": "bio",
       "damage_type": "�ζ�",
    ]),
    ([ "action": "$N�k�x���M�_�X�@�Τ����A���O�֪L���ǡu"HIR"�����x"NOR"�v$N���Τ@�̡A�x�����V$n$l",
       "damage": 15,
       "dodge" : 10,
       "parry" : 13,
       "attact_type": "wit",
       "damage_type": "�N�ˡA�S��$n�z�z�j�s",
    ]),
});

string *colors = ({
  HIM"",
  HIR"",
  HIG"",
  HIB"",
  HIY"",
  HIW"",
});

mapping query_action()
{
    return combat_action[random(sizeof(combat_action))];
}

void heal();
void create()
{
    set_name("�v����P", ({"food god", "god"}) );
    set("long",@LONG
    �e�u��¡v�������θ��ƪ��A�P�ɤ]�O���䶼���ɲĤ@���ȡA
���y�����z���٪��k�H�w�v����P�C�b�@���s���}���ɳQ�t�@������
�Τj�ּ֪�����ҳ��`�A�H�Ͷ^���쨦���C��Ӿa�����M�����P��{
�V�V�̪�����A�H�u�������Y�v���X����A�����b����p���V�m�ǰ|
�Ǧ��X���A�P�ɦb�s�@�������j�ɤW�⮩�F�ܰ����n��C�{�b���v��
��P�w�g�����@��b�H�b���������P�F�C
LONG );
    set("race", "beast");
    set("race","�H��");
    set("gender","�k��");
    set("age", 29);
    set("level", 50);
    set("title",HIY"����"NOR); 
    set("con", 100);
    set("int", 100);
    set("dex", 100);
    set("str", 100);
    add("addition_damage", 150);
    add("addition_armor", 250);
    set("chat_chance", 5);
    set("chat_msg", ({
        (: command, "say ���M�N...�Ȥd��..." :),
        (: command, "say �W�M�s�U����...�S���..." :),
        (: command, "say ������...�묹�S�����..." :),
        (: command, "say ���b��...�m�W�@����..." :),
        (: command, "say ��\\�����y...�ܦ��L����..." :),
        (: command, "say ���֤H...���L��..." :),
    }));
    setup();
    set("default_actions", (: call_other, __FILE__, "query_action" :));
    set("actions", (: call_other, __FILE__, "query_action" :));
}
int special_attack(object me, object target, int hitchance)
{
    string msg;
    int i;
    if( !me || !target ) return 0;
    if( target->is_busy() ) return 0;
    if( random(100) < 25 ) {
        message_vision(HIC"\n$N"HIC"���M���S�X�F�f�M������A�æb�@���������X�J���Q�Q���e�N���I\n\n"NOR, me, target);
        if( random(100) < target->query("level")/2 ) {
            message_vision(HIG"\n$N"HIG"�O�ɤߤO�J��ۤv�������A�ש���L�F�e�N�������b�I\n\n"NOR, target, me);
            return 0;
        }
        message_vision(HIR"\n$N"HIR"�����F�e�N�������b�A�j�f�j�f�a�ڰ_���ӡI�h���y���Y�۬������e�N�I\n"NOR, target, me);
        for(i=random(5)+2;i>=0;i--) {
            switch( i ) {
                case 0: msg = "$N���y�h�W���j�۵ۡG�n�O�H��Y�������I\n"; break;
                case 1: msg = "$N���D�G�n�e�N���I�e�N�n�Y���I�C���׳��Q���l�Ҿ_�_�A���r�l�S�����f�I\n"; break;
                case 2: msg = "$N��M�j���a���D�G��ӬO�[�F�v���I�u�O���f�M�I�Ӯ���F�I\n"; break;
                case 3: msg = "$N���M�����n�j���F�_�ӡA���G�J�줰��ߵh���Ʊ��I������|�y�\\�I�H\n"; break;
                case 4: msg = "$N��ĵۡG�o���]�J�u�O�Ӭ����F�I�����x�N�J�������������o�X�ӡI�u�O�ӴΤF�I\n"; break;
                case 5: msg = "$N�j�s�D�G�S�Q�콭��]�঳�p���ĥΡI�N��Ӥe�N�������D��Ũ���F�X�ӡI\n"; break;
                case 6: msg = "�e�N���������O$N�j�֦��[�A���O�C�Y�@�f�N��K���Y�A����]�����t�H�F�U�h�I\n"; break;
                default: msg = "$N�Ԥ����g�����f�G�Ӧn�Y�F�A�u�O�Ӧn�Y�F�C\n"; break;
            }
            message_vision("\n$N�C�Y�@�f�e�N���A�K���ѦۥD���o�X�g���n�A�o�S�o�{�o�f�M�P��w�Ϧۤv���줺�ˡI\n", target, me);
            message_vision(colors[random(sizeof(colors))]+msg+""NOR, target, me);
            switch( random(6) ) {
                case 0: target->receive_wound("head", 3 + random(15)); break;
                case 1: target->receive_wound("body", 3 + random(15)); break;
                case 2: target->receive_wound("left_arm", 3 + random(15)); break;
                case 3: target->receive_wound("left_leg", 3 + random(15)); break;
                case 4: target->receive_wound("right_arm", 3 + random(15)); break;
                case 5: target->receive_wound("right_leg", 3 + random(15)); break;
                default: target->receive_damage("hp", target->query("max_hp")/3); break;
            }
        }
        target->receive_damage("hp", target->query("max_hp")/6);
        message_vision(HIM"\n$N"HIM"�ש�N�f�M�P��Y�Ӻ���A�����Ӫ����G�O�ߤO���L�O�A�ԡI\n"NOR, target, me);
        target->start_busy(2+random(3));
        COMBAT_D->report_status(target);
    }
    return 0;
}
