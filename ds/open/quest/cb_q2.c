// tmr 2007/03/10

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�d�z�H����";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "���Y�N�x�Ʊ�A��d�z�H���몺�x�O�C\n";
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
    if( player->isSolved("/open/quest/cb_q1.c") == -1) return 0;
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
        "$N���$n���D�G�p���ڭ̤w�g���D�H���몺�@�ԭp�e�A���O�L�̧L�O���M�Q���j�j�C\n",
        "$N���$n���D�G�ڭ̨M�w���A�h�H����A�d�z�L�̪��ԤO�I�I\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/orc_follower.c": 30,
        "/open/world1/tmr/crush_bone/npc/orc.c": 30,
        "/open/world1/tmr/crush_bone/npc/orc_hundred_leader.c": 20,
        "/open/world1/tmr/crush_bone/npc/orc_thousand_leader.c": 20,
        "/open/world1/tmr/crush_bone/npc/orc_commander.c": 10,
        "/open/world1/tmr/crush_bone/npc/orc_herald.c": 5,
        "/open/world1/tmr/crush_bone/npc/orc_envoy.c": 5,
    ]);
    return item;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
//        return ([]);
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/obj/orc_skull.c": 10,
    ]);
    return item;
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
        "$N���$n���D�G���I�F���n�ڡI�I�A����O���T���e�m�áC\n",
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

