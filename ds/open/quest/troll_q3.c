// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

void create() { seteuid(getuid()); }

// ���ȦW��
string getName() {
    return "�M���������]";
}

// ���ȴy�z
string getDetail() {
    string msg;

    msg  = "�]�a���y���b�_��j�˪L�ǡA�ѩ�˪L����ۭ��H�ת����]�A�������\n";
    msg += "�L�۴��ߦQ�x���ͬ��A�v�ڪ��Ʊ�A��i�@�B�����M���������]�C\n";

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
   if( player->isSolved("/open/quest/troll_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/troll_q2.c") == -1) return 0;
    return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/faceoff/sky/npc/meo_chung.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�˪L�`�B���Ӧa���}�ޡA���Y��ۻ������]�C\n",
        "$N���$n���D�G���F�]�a�����w���A�@�w�n�N�������]�������I�I\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/north_forest/npc/troll6.c": 3,
        ]);
    return kill;
}

// ���ȶ��n���o�Y�Ǫ��~�A�Y���ݭn�h return 0
// �`�N�G�o�Ǫ��~���ݬO�ƦX������~��
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

// �������Ȯɪ��T��
string *getRewardMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�u�O�����§A�������I\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
    return "
�԰����N 6 �I�C
�n�� 3 �I�C
�H��60% �O�q�B���B���z�B�ӱ����b�@�i�C
";
}

string *items = ({
         "60_str.c",
         "60_con.c",
         "60_dex.c",
         "60_int.c",
});


void reward(object player, object npc) {
    player->add("popularity", 3);
    tell_object(player, HIY"(�A��o�F 3 �I�n��C)\n"NOR);
    player->add("war_art", 6);
    tell_object(player, HIY"(�A��o�F 6 �I�԰����N�C)\n"NOR);
    new("/open/enhance/" + items[random(4)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);

}

