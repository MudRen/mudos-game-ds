// tmr 2007/03/10

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�t���H���ӫ�";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�o�@���A���Y�N�x�Ʊ�A��t���H���몺�ӫҡA�n�G�L�̰h�x�C\n";
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
    if( player->isSolved("/open/quest/cb_q1.c") == -1) return 0;
    if( player->isSolved("/open/quest/cb_q2.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/dragoncity/npc/ma-ruo.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/ma-ruo.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�o�H����@�餣���A�Y�s���N�@�餣�w���C\n",
        "$N���$n���D�G�p���ڭ̫D�`�֩w�A����O�A�ҥH�Ʊ�A�৹���o�@�ӦM�I�����ȡC\n",
        "$N���$n���D�G�ڭ̨M�w���A�h�H����A�����L�̪���t��-�H���ӫҡI�I\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/orc_emperor.c": 1,
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
        "$N���$n���D�G���I�o�O�Ӧn�F�A�H���ӫҤ@���A�H����N�s�s�L���F�C\n",
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


