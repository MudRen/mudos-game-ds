// tmr 2007/03/10

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�H�����";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "���ӥb�~�H��G��ذ��a�A�粱�i�H���A���ҥX�H������C\n";
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
    return "/open/world1/tmr/dragoncity/npc/tao-sheng.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/tao-sheng.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�H���몺�b�~�H��G�㦳�_�����r�ġC\n",
        "$N���$n���D�G�p�G�Aı�o�ۤw�u�O�Ӥj�A�ڭˬO�i�H���A�@�Ӧ��C\n",
        "$N���$n���D�G���ӥb�~�H��G��ذ��a�A�ڥi�H���ҥX�H������C\n",
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
//        return ([]);

    mapping item = ([
        "/open/world1/tmr/crush_bone/npc/obj/orc_blood.c": 1,
        "/open/world1/tmr/crush_bone/npc/obj/orc_rib.c": 1,

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
        "$N���$n���D�G��A�ڰ��W�N�����A�A�еy���@�U�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�@���H�����(crush-bone blood)�C\n";
    msg  += "�g��� 1,000 �I�C\n";
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
        new("/open/world1/tmr/crush_bone/npc/obj/blood.c")->move(player);
        tell_object(player, HIY"(�A��o�@���H������C)\n"NOR);
    player->add("exp", 1000);
    tell_object(player, HIY"(�A��o�F 1,000 �I�g��ȡC)\n"NOR);
}

