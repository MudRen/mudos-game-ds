// 2009/05/12

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�d�z�]�פj�x";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�o���A�����ͪZ�ǡA�h��{��d�z�]�פj�x����O�C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 40;
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
        "$N���$n���D�G�A����O�w�g���e�h�áA���O�٦����}�������Ȼݭn�A�h�����C\n",
        "$N���$n���D�G�o���A���Z�Ǹ�ݤO�A�h��{��d�z�]�פj�x����O�I\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/blood_field2/npc/fetish.c": 30,
        "/open/world1/tmr/blood_field2/npc/cat.c": 30,
        "/open/world1/tmr/blood_field2/npc/fetish_wizard.c": 20,
        "/open/world1/tmr/blood_field2/npc/hulks.c": 10,
        "/open/world1/tmr/blood_field2/npc/wendigo.c": 10,
        "/open/world1/tmr/blood_field2/npc/wild_toast.c": 5,
        "/open/world1/tmr/blood_field2/npc/ents.c": 2,
    ]);
    return item;
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

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�A�S�A�@���ҩ��A����O�A�֫ӭx����W�U���D�`�P�§A���I�X�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�g��� 1,500,000 �I�C\n";
    msg += "�Ԫ����N 350 �I�C\n";
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
      player->add("exp", 1500000);
      tell_object(player, HIY"(�A��o�F 1,500,000 �I�g��ȡC)\n"NOR);
     player->add("war_art", 350 );
     tell_object(player, HIY"(�A��o�F 350 �I�԰����N�C)\n"NOR);
}

