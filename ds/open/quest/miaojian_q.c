// tmr 2007/02/28

#include <ansi.h>

void create() { seteuid(getuid()); }



// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "�������аU";
}

// ���ȴy�z
string getDetail() {
    string msg;
        msg = "�����������ⶳ�x�e������A�����p���D�A�z�ڲ`�p�A���~�ɴ��]�t�ڷ|\n";
        msg += "�߱o������Ĥ@���ޡu�p�ӤE���v�A�ۦ���B�Z�G�D���������A�׬��X�H�F\n";
        msg += "��u�i�ơv���ҬɡA�Ʊ�A�����L���o�p�Ӧ�ߡA�W�q�L���׬��C\n";
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
    return "/open/world1/tmr/advbonze/npc/bonze_adv_master.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/advbonze/npc/bonze_adv_master.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�p�Ӧ�߬��@�����i�h�o����иt���A�Ʊ�A�����ڨ��o�@���C\n",
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
        "/open/world1/tmr/advbonze/npc/obj/heart.c": 1, // �p�Ӧ��
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
        "$N���$n�L�����D�G�u�O�����§A�F�A�ڦ�O�d�A��������C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�g��� 100,000 �I�C\n";
    msg += "�n�� 10 �I�C\n";
     msg += "�԰����N 50 �I�C\n";
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
        player->add("popularity", 10);
    tell_object(player, HIY"(�A��o�F 10 �I�n��C)\n"NOR);
         player->add("war_art", 50);
      tell_object(player, HIY"(�A��o�F 50 �I�԰����N�C)\n"NOR);
  

}

