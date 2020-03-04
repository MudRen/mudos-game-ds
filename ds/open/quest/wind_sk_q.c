// �����߳Z(indicate-knack) - �e���i���ޯ�

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
    return "�����߳Z";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�u�����߳Z�v�O�e���������ޡA�A�����q�����H��\n";
    msg += "���ӥ��K�C�Υɤk�C�A�~�����ǲ߳o���ޯ�C\n";

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
   if( player->query("class2") != "�e����" ) return 0;
   if( player->query_skill("star-sword") < 90 ) return 0;
   if( player->query_skill("moon_force") < 90 ) return 0;

   // ���ǹL�N����A�ѤF
   if( player->query_skill("indicate-knack") > 0 ) return 0;
   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/cominging/area/npc/yuanlieh.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�����߳Z�v�O�������ޡA�u�ǵ�����O���̤l�C\n",
        "$N���$n���D�G�����H�Ӫ����K�C�Υɤk�C���Z�L�������L�Q���C\n",
        "$N���$n���D�G�h���ӵ��ڧa�A�n�����p���o�Ӹ��C\n"
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
   return ([]);
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
mapping getItem() {
    mapping item = ([
        "/open/world1/moonhide/area/sword.c": 1,        // ���K
        "/open/world1/moonhide/area/sword3.c": 1,               // �ɤk
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

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/cominging/area/npc/yuanlieh.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G���������A�A�G�u���ڨ��ӳo��⯫�L�Q���I\n",
        "$N���$n���D�G�n�{�̡A�ڳo�N�ǵ��A�o�����ޡC\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg = "�߱o�u�����߳Z(indicate-knack) �v";
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
        player->set_skill("indicate-knack", 10);
}

