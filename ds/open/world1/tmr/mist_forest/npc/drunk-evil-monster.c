#include <npc.h>

void create()
{
        set_name("�ܾK���]�~", ({ "drunk evil monster","monster" }) );
        set("long",@long
    �o�O�@�����o�H�ҤH�˪��Ǫ��A���O�A�i�H�M���@���e������������
�u��A�Ӫ��p�h���Ӵ��o�����������������ۧA�A�e�Ⱖ���u���i�ν��A����
�ۤ��j�ڦp�¦��K����y�U�����ҡA���G�H�ɳ��i�H��A������b�C���O�e��
�G�s��������í�F�A�@�y�K�H�H���ˤl�C
long
);
        set("title","�g���˪L");
        set_race("human");
        set("age", 120);
          set_skill("sword",120);
          set_skill("parry",120);
        set_skill("dodge",60);
          // �����]�~�A��o�� 5�I�n��
        set("bounty",([
                "reputation":5, 
        ]) );
        setup();
          set_level(35);  // �]�~ �O�ܱj��....
        carry_money("gold", 1);
        /* �򥻸˳� */
        carry_object(__DIR__"obj/evilmonster-armor")->wear();
        carry_object(__DIR__"obj/python-belt")->wear();
        // only sword�G�s����C
        carry_object(__DIR__"obj/dominate-sword")->wield();
}

