// tmr 2007/07/15

#include <ansi.h>

// �������ɬO���ȡA�o�Ө禡���ݭn�ܰ�
int isQuest() { return 1; }

// �i���б�
int isNewly() { return 1; }

// ���ȦW��
string getName() {
    return "���ħJ�i�h������ III";
}

// ���ȴy�z
string getDetail() {
    string msg;
	msg = "�կT���O���ħJ�ǯT���u�@���A�o�@���A�A�o�n�Q�k�l�����կT���C\n";
	msg += "�կT�����`���ðεۡA�S���H�i�H���e�F����e���l���Q�ݱ��ɡA�e�N���i��|�{���F�C";
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
   if( player->isSolved("/open/quest/hasake_q1.c") == -1) return 0;
   if( player->isSolved("/open/quest/hasake_q3.c") == -1) return 0;
   return 1;
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getAssigner() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// �������Ȫ�NPC  (�H�ɦW���ѧO)
string getRewarder() {
    return "/open/world1/tmr/hasake/npc/su.c";
}

// �������Ȯɪ��T��
string *getAssignMessage() {
    // $N��NPC, $n��player
    string *msg = ({
        "$N���$n���D�G�կT���O���ħJ�ǯT���u�@���A�o�@���A�A�o�n�Q�k�l�����e�C\n",
    });

    return msg; 
}

// ���ȶ��n�����Y�ǩǪ��A�Y���ݭn�h return 0
mapping getKill() {
    mapping kill = ([
        "/open/world1/tmr/hasake/npc/white-wolf.c": 1, 
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
        "$N���$n���D�G�A�u�O�@�Ӱ��j�����ħJ�i�h�A���ԯu���@�w�|���֧A�C\n",
    });

    return msg;
}

// ���Ȥ�x�W�����y����
string getReward()
{
     return "
100%, 60%, 10% ���z���b�H���G�i�C
�԰����N 3 �I�C
";
}

string *items = ({
	"10_int.c", "60_int.c" , "100_int.c"
});


void reward(object player, object npc) {
    player->add("war_art", 3);
    tell_object(player, HIY"(�A��o�F 3 �I�԰����N�C)\n"NOR);

    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
    new("/open/enhance/" + items[random(3)])->move(player);
    tell_object(player, HIY"(�A��o�@�i���b�C)\n"NOR);
}

