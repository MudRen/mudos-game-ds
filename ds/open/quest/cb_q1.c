// tmr 2007/03/10

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���o�@�ԭp�e";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "���Y�N�x�Ʊ�A����o�H���몺�@�ԭp�e�A�n���w�U�@�B���i��C\n";
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
        "$N���$n���D�G�ڧƱ�z��i�h�H����A�����L�̪��S�ϡA���o�@�ԭp�e�C\n",
        "$N���$n���D�G�p���@�ӡA�ڭ̤~�n�H�h�ݳҡA���w���U�Ӫ��𨾦�ʡC\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/orc_envoy.c": 1,
    ]);
    return item;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
//return ([]);
    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/obj/war_plan.c": 1,
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
        "$N���$n���D�G���I�F���n�ڡI�I���F�o�ӧ@�ԭp�e�A�ڭ̴N�Ө��b���I�I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�g��� 100,000 �I�C\n";
    msg += "�Ԫ����N 10 �I�C\n";
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
    player->add("exp", 100000);
    tell_object(player, HIY"(�A��o�F 100,000 �I�g��ȡC)\n"NOR);
    player->add("war_art", 10);
      tell_object(player, HIY"(�A��o�F 10 �I�԰����N�C)\n"NOR);
}

