#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�D�԰��s�]��";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�]�׬O��{�����D�A�O�@���D�`�j�����s�A�A�o�������ȴN�O�h�D�ԩ]�סA�ñ����e�C\n";
    msg  += "�A�����n���q����H���W���o�u�]�ׯQ�ۡv�A�æb���s�g�������H(crumb)�A\n";
    msg  += "�~��N�]�ת����v�q�@������{�X�ӡA�p���@�ӡA�A�~��D�ԥL�C\n";
    
    return msg;
}

// ���ȵ���
int getLevel() {
    return 45;
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
    if( player->query("level") < 40 ) return 0;
    if( player->isSolved("/open/quest/bf_q1.c") == -1) return 0;
      if( player->isSolved("/open/quest/bf_q2.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/du-qing.c";
}


// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�]�׬O��{�����D�A�O�@���D�`�j�����s�A�A�o�������ȴN�O�h�D�ԩ]�סA�ñ����e�C\n",
        "$N���$n���D�G���O�]�׳����æb���s�g�������A�A�����n���q����H���W���o�u�]�ׯQ�ۡv�A\n",
        "$N���$n���D�G�æb���s�g�������H(crumb)�A�~��N�]�ת����v�q�@������{�X�ӡA�p���@�ӡA�A�~��D�ԥL�C\n",
        "$N���$n���D�G�o�O�@���D�`�}�������ȡA�Ʊ�A�ର�ѤU�a�ͺɤ@���O�C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping item = ([
       "/open/world1/tmr/blood_field2/npc/nightbane.c": 1,
     ]);
    return item;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
        return ([]);
/*
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/obj/war_plan.c": 1,
    ]);
    return item;
*/
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

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�S�A�@���������i�઺���ȡA�֫ӭx����W�U���D�`�P�§A���I�X�C\n",
            });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
      msg  = "�g��� 300,000 �I�C\n";
    msg += "�Ԫ����N 30 �I�C\n";
    return msg;
}

/*  ���ȼ��y
    ���y���ӯ�ۥѵo���A�p�G
        1. ��o�g��
        2. ��o���~
        3. ��o�u��Buff
        4. �߱o�Y�ޯ�
        5. ��缾�a���A, ex: ��¾
 */
void reward(object player, object npc) {
     player->add("exp", 300000);
     tell_object(player, HIY"(�A��o�F 300,000 �I�g��ȡC)\n"NOR);
    player->add("war_art", 30);
    tell_object(player, HIY"(�A��o�F 30 �I�Ԫ����N�C)\n"NOR);
}

