#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�`�w����";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�u���䶯�A�u��ۡA���ѤU�ơC���ѤU�ơA�`�w�����A�_�k������v�C\n";
    msg += "�A�i�H�b�P�U��������S�H������M�A�Ӷi�@�B���m�`�w�����n���u�͡C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 50;
}

/* �������Ȫ��e�m����A�i��O
        1. ���ŻݨD
        2. ¾�~�ݨD
        3. �رڻݨD
        4. �w�����Y�ǥ��ȻݨD
    �����A���i�H�ۥѵo���~�O�C
    �^�ǫD�s�Ȫ�ܲŦX����C
 */
int preCondition(object player) {
        // �������o��ޯ�
    if( player->query_skill("constant-virtue") == 0 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���䶯�A�u��ۡA���ѤU�ơC���ѤU�ơA�`�w�����A�_�k������C\n",
        "$N���$n���D�G�A�i�H�b�P�U��������S�H������M�A�Ӷi�@�B���m�`�w�����n���u�͡C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/bagi/npc/advmaster.c": 1,             //�d��
        "/open/world1/cominging/area/npc/yuanlieh.c": 1,        //�a�կP
        "/open/world1/tmr/advthief/thief_adv_master.c": 1,      //���
        "/open/world1/kkeenn/love/npc/master_2.c": 1,           //����
        "/open/world1/tmr/advbonze/npc/bonze_adv_master.c": 1,   //����
        "/open/world1/acme/area/npc/advmaster.c": 1,            //����s
        "/open/world1/tmr/frost/npc/yun-zhong-zi.c": 1,         //�����l
        "/open/world1/tmr/dragoncity/npc/kou-zhong.c" : 1,      // �F��
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
        return ([]);
}


// �������Ȫ����󰣤F�t�δ��Ѫ�
// 1. �j�����~
// 2. ���F�����ƶq���Ǫ����~
// ���ݭn���ܡA�٥i�H�ۭq�������ȱ���
// return 1, ����������, return 0;������
int postCondition(object player, object npc)
{
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/endless/npc/master.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���������A�A���T�����X�A����O�F�I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg = "";
    msg += "��o�u�`�w�����v���[��(�W�[5%�����v�A����ɶ��G�`�w��������*30����)�C\n";
    msg += "�԰����N 50 �I�C\n";
    return msg;
}

void reward(object player, object npc) {
        player->add("war_art", 50 );
        tell_object(player, HIY"(�A��o�F 50 �I�԰����N�C)\n"NOR);

        if(!player->query_temp("constant-virtue")) {
                player->set_temp("constant-virtue", 5);
                player->add_temp("apply/hit_ratio", 5);
        }
        player->apply_condition("constant-virtue",
                4 * 30 * player->query_skill("constant-virtue")
        );
        tell_object(player, HIY"�L���ɮv��J�A�����`�B�A�A�P����@�ѤO�q�����ӥ͡C\n"NOR);
}

