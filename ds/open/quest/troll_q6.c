// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

void create() { seteuid(getuid()); }

// ���ȦW��
string getName() {
    return "�t�ٳ������˳Ƨ���";
}

// ���ȴy�z
string getDetail() {
        return 
"�]�j�T���F�P�§A��]�a���������A�@�N���A�s�y�t�ٳ������˳ơA
�䤤�˪����٤��æ��Ǹ������]�p�ϡA�A�����q�B�����]�B���o�A�t�~
�A�٥������ѦB���֦�δX�ӦB���n��A�����s�y���ǸȪ����ơC
"; 
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
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q2.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q3.c") == -1) return 0;

    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/meo-aunt.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/meo-aunt.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�O�D�`�P�§A��]�a���������C\n",
        "$N���$n���D�G�n�O�A����Ӭ�������ơA�ڥi�H���A�_�s�t�ٳ������˳ơC\n",
        "$N���$n���D�G�䤤�˪����٤��æ��Ǹ������]�p�ϡA�A�����q�B�����]�B���o�C\n",
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
        "/open/world1/tmr/north_forest/npc/obj/troll-ring2.c": 1,
        "/open/world1/tmr/north_forest/npc/obj/frost-cloth2.c": 1,
        "/open/world1/tmr/north_forest/npc/obj/frost-fur.c": 3,
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
        "$N���$n���D�G�A����Ƴ����ӤF�A�ڰ��W�N�s���A�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return 
"
�k�ʨ���i��o�t�٥��]��ǡF�k�ʫh��o�t�٥��]��ȡC
�g��� 50,000 �I�C
";
}



void reward(object player, object npc) {
    player->add("exp", 50000);
    tell_object(player, HIY"(�A��o�F 50,000 �I�g��ȡC)\n"NOR);

        if( player->query("gender")=="�k��" ) {
                new("/open/world1/tmr/north_forest/npc/obj/troll-pants")->move(player);
                tell_object(player, HIY"(�A��o�@��t�٥��]��ǡC)\n"NOR);
        } else {
                new("/open/world1/tmr/north_forest/npc/obj/troll-skirt")->move(player);
                tell_object(player, HIY"(�A��o�@��t�٥��]��ȡC)\n"NOR);
        }
}


