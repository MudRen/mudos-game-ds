// tmr 2007/03/10

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�챴�L�����";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�궳�M�|�Ʊ�A��h�L�������ӤT�Q���L��P�l��Q�ɶ����ۡA�n�ҩ��A����O�C\n";
    return msg;
}

// ���ȵ���
int getLevel() {
    return 35;
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
    if( player->query("level") < 35 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/acme/bonze/npc/master.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/acme/bonze/npc/master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�L�����O�b�s�V�j�D�W���@�B����A���Y��ۺɬO�F�������C\n",
        "$N���$n���D�G�ڧƱ�A�ର�ѤU�a�ͺɥ��ߤO�A�h�������A�b�����e�A�n���ҩ��A����O�C\n",
        "$N���$n���D�G�o��I�D�����ӤT�Q���L��P�l��Q�ɶ����ۡC\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
        return ([ ]);
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
//return ([]);
    mapping item = ([
        "/open/world1/tmr/unquiet_manor/npc/obj/q_plate.c": 30,
        "/open/world1/tmr/unquiet_manor/npc/obj/q_stone.c": 10,
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
        "$N���$n���D�G��������I�I�I�D�\\�w�L�q�I\n",
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
    tell_object(player, HIY"(�A��o�F 30 �I�԰����N�C)\n"NOR);
}


