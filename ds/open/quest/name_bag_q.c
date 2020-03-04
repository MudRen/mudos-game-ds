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
    return "�B�F�������_�v";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "���B�F��´�����������_�v�B�t��A�]���e�ӧ�\n";
    msg += "�o�s�@��A���U�ȶV�ӶV�֡A�Ȫ����]�V�ӶV�֡A\n";
    msg += "�K�M�w�n�Φۨ������_�������Ǧ�A�H�~���F����\n";
    msg += "�~�֡C\n"; 
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
     if( player->query_capacity() > player->query_max_capacity()/2 ) return 0;
   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/cominging/area/npc/spinner.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���D�R"+HIY+"�o��ȤH�A�z�O�|�B�Ȧ檺�_�I�̧a�A�ݧA���۳o��h�F��A�ݤ��ݭn�����z�_�s�@�ӳU�l�O�H\n"NOR,
        "$N���D�R"+HIY+"�u�n���ڦ����@�ǧ��ơA�M���ڤ@�I�u���A�ڴN�i�H���z���Ӧn�Ϊ��U�l�C\n"NOR,
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
        "/open/world1/whoami/birdarea/npc/obj/bag.c": 1,        // �����U
        "/open/world1/cominging/purple_sun/npc/obj/stomach-bag.c": 1,               // �~���G�U
        "/open/world1/obj/gold_tackle.c": 1, // ��������
        "/open/world1/wilfred/sand/npc/eq/eq4.c": 1, // �ȯT��
        "/open/world1/moonhide/area/leather3.c": 1, // �����
        "/open/world1/eq/viper_cloth.c": 1, // ���A�Ԧ�
        "/open/world1/cominging/area/npc/obj/cloth3.c": 1, // �ȵ�
        "/open/world1/moonhide/pool/npc/obj/snake-waist2.c": 1, //���b�a
        "/obj/money/coin.c": 10000, // 10000 coin
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
    return "/open/world1/cominging/area/npc/spinner.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�еy���@�U�A�ڰ��W���z�_�s�C\n",
        "$N�V$n�D�¡C\n",
        "$N�b�P��$n����A�����$n�ҵ�$N�����Ʃ�b�u�@�x�W�}�l���ŤF�_�ӡI\n",
        "$N���۵��Ŧn�����Ʀb�_�����e�u�@�C\n",
        "$N���_�_�n���U�l����t�װŤF�@�U�C\n",
        "$N���_"WHT"�ȵ�"NOR"�ΰ������������U�l¸�W�ϮסA�æb�U�f�����"HIY"����"NOR"¸�W�F�A���W�r�C\n",
     HIY"(�@�ӳU�l�N�o�򧹦��F)\n"NOR,
    });
    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
     string msg = "��o�u����p�N�U �v�@�u�A�B�W��¸���z�ӤH���W�r�C\n";
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
        object ob = new("/open/world1/cominging/area/obj/ingenious_bag.c");
        ob -> set("name",HIC"����"HIW"�p�N�U"HIM"�i"HIY+player->query("id")+HIM"�j"NOR);
        ob -> move(player);
}

