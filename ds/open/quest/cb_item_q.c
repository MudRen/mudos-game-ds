// tmr 2007/03/10

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�b�~�H���e";
}

// ���ȴy�z
string getDetail() {
    string msg;
    msg  = "�N�b�~�H���e�ߵ��J�R�A�L�൹�A�@�Ǽ��y�C\n";
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
    if( player->isSolved("/open/quest/cb_q3.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/dragoncity/npc/hu-mai.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/dragoncity/npc/hu-mai.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�o��^�����Y�s���ߪ��\\�үu�j�C\n",
        "$N���$n���D�G�n�O�A��N�b�~�H�����e�ߨӵ��ڡA�گ൹�A�@�Ǽ��y�C\n",
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
        "/open/world1/tmr/crush_bone/npc/obj/orc_rib.c": 5,
        "/open/world1/tmr/crush_bone/npc/obj/orc_shin_bone.c": 10,
        "/open/world1/tmr/crush_bone/npc/obj/orc_skull.c": 10,
          "/open/world1/tmr/crush_bone/npc/obj/orc_foot.c": 10,
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
        "$N���$n���D�G���I�I�o�u�O�Ӧn�F�I�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg = "�g��� 50,000 �I�C\n";
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

    player->add("exp", 50000);
    tell_object(player, HIY"(�A��o�F 50,000 �I�g��ȡC)\n"NOR);
}

