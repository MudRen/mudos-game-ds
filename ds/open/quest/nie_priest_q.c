
// tmr 2007/07/15

#include <ansi.h>

void create() { seteuid(getuid()); }

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "¿�������ШD";
}

// ���ȴy�z
string getDetail() {
        string msg;
        msg = "¿�����Q�n�@�ǪF��j��ƪ��򪫡A�Ʊ�A�৹���L�����@�C\n";
        return msg;
}

// ���ȵ���
int getLevel() {
      return 5;
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
   if( player->query_skill("literate") < 60 ) return 0;
   if( player->query_skill("literate") >= 100 ) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/north_bar/npc/nie.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/north_bar/npc/nie.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�Gť�����b���ħJ���A���@�ǭ��n���F�~�۾��C\n",
        "$N���$n���D�G�ڥ��}�F���ƫܤ[�F�A�����D�A��_���ڨ��o�@�ǥ۾��H\n",
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
        "/open/world1/tmr/hasake/npc/obj/stone1.c": 3, 
        "/open/world1/tmr/hasake/npc/obj/stone2.c": 3, 
        "/open/world1/tmr/hasake/npc/obj/stone3.c": 3, 
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
        "$N���$n���D�G�u�O�ӷP�§A�F�C\n",
        "$N���$n���D�G�o���t�g�N�e���A�A�@�W�ү��֧A�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    string msg;
    msg  = "�@���t�g�C\n";
    return msg;
}


void reward(object player, object npc) {
    object bible;
    bible = new("/open/world1/tmr/north_bar/npc/obj/bible.c");
    bible->move(player);
    tell_object(player, HIY"(�A��o�@���t�g�C)\n"NOR);
}


