// stake.c ���H 
// 2002/04/13 -Tmr
// update -Acme-

inherit NPC;

#define LIFE 8000

void create()
{
    set_name("�_��H", ({ "scarecrow stake", "stake", "_OBJ_STAKE_" }) );
    set_race("human");
    set("long", "�@�Ӱ����ݮݦp�ͪ��_��H�A�Ψ��~���p���Ϊ��C\n");

    // ���H���ͩR��
    set("stake_life",LIFE);
    setup();
    delete_stat("hp");
}

int accept_fight(object ob)
{
    return 1;
}

varargs int attack(object opponent)
{
        //���H���|����
        return 0;
}
int defend(int ability, int strength, object from)
{
        // �L�k���\���m
        return 0;
}

int absorb(int ability, int strength, object from)
{
        // �L�k�����O�D
        return 0;
}

//���H�S�����m��
int resist_damage(int damage, object from_ob)
{
        return 0;
}

varargs int receive_damage(int damage, object from, object attacker)
{

        string skill;
        // �S��������
        if(!attacker) return 0;
        skill=attacker->query_temp("attack_skill");
        //�S�������ޯ�A�����g���
        if(!stringp(skill)) return 0;
        // �P�_�������ޯ�A�j�� 50 �šA�h�N�L�k�Q�ΰ��H�m�\�C
        if( attacker->query_skill(skill,1) >= 50) return 0;


        // ���H���ͩR �P�_
        add("stake_life",-damage);
        if( query("stake_life")<0 ) {
                message_vision("�u�ذաv���n�T�A$N�ܦ����H���A�������a�F�C\n",this_object());
                remove_all_killer();
                call_out( (:destruct($1):),1,this_object());
        }       
        return damage;
}

