/*  TestQuest.c

�@�ӥΨӴ��ե��Ȩt�Υ��T�ʪ����եΥ��ȡA�]�O���ȼ��g���d�ҡC

�ثe���Ȥ䴩�����G
1. �����Y�Ǽƶq���Ǫ�
2. ���o�Y�Ǽƶq�����~
3. �y�X�ʥ���  (�N���YA�n�A�h��YB�A�Y�i��������)

�`�N�G�]���H�ɦW���ѧO�A�b�]�w���ɦW�O�o�[�W .c 

    write by Acme- 2007.02.04
 */

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

/* �����ȬO�_�୫�Ƹ�  return 0  ���୫��
                       return 1  �i����
   ��ĳ�̦n�]�w���୫�ơC
 */
int isNewly() { return 0; }

// ���ȦW��
string getName() {
    return "�n�Ԫ��Τ�";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�s������W�������s�w�g�Ƥd�~�S���԰��F�A�L���l�̪���G�E����\n";
    msg += "���A�L�Ʊ�A�N�L�h�ѻP�@���Ԫ��Ať���ѫ����өx�ѷݫ~�ʤ��}�A\n";
    msg += "�Q���Ӧ����å�C\n";

    return msg;
}

// ���ȵ���
int getLevel() {
    return 30;
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
if( player->query("level") < 30 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/area/npc/shan.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        CYN"$N�`�`���ĤF�@�f��C\n"NOR,
        "$N���$n���D�G�o�Ǥ�l��b�L���o�e�C\n",
        "$N���$n���D�G�ڤw�g�X�d�~�S���԰��F�A�ڪ���G�w�g�E������ڡI\n",
        "$N���$n���D�Gť���ѫ����өx�ѷݫ~�ʤ��}�A�Q���Ӧ����å�C\n",
        "$N���$n���D�G�p�G�A�����ڥh�ѥ[�Ԫ����ܡA�ڷ|�P�E�A���C\n",
    });

    return msg;
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/acme/cominging/npc/soldier.c": 50,  // �h�L
        "/open/world1/acme/cominging/npc/general.c": 40,  // ���N
        "/open/world1/acme/cominging/npc/general2.c": 30,  // �t�N
        "/open/world1/acme/cominging/npc/chief.c": 20,     // �ʤҪ�
        "/open/world1/acme/cominging/npc/chief2.c": 15,    // �d�Ҫ�
        "/open/world1/acme/cominging/npc/leader.c": 10,    // �`�L
        "/open/world1/acme/cominging/npc/lord.c": 6,      // ���`
        "/open/world1/acme/cominging/npc/lu.c": 1,        // ����
        "/open/world1/acme/cominging/npc/gu.c": 1,        // ����
        "/open/world1/acme/cominging/npc/chung.c": 1,     // �L�R
    ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���O�ƦX�����]�A��
mapping getItem() {
return ([]);
/*
    mapping item = ([
        "/world/area/old_forest/npc/item/monkey_tooth.c": 10, // �U��
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

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/area/npc/shan.c";
}

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G��b�O�ӴΤF�A�ڹ�b�O�ӿ��ĤF�I\n",
        "$N���$n���D�G�u�O�P�§A�r�I\n",
        CYN"$N�ּ֪���R���СC\n"NOR,
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�g��� 500000 �I�C\n";
    msg += "�԰����N 200 �I�C\n";
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
player->add("war_art", 200);
    tell_object(player, HIY"(�A��o�F 200 �I�԰����N�C)\n"NOR);

player->add("exp", 500000);
    tell_object(player, HIY"(�A��o�F 500000 �I�g��ȡC)\n"NOR);
}
