#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N���M���S�@�n, ���O�r�M�������x,  "+WHT+"�u"+NOR+"�ʬP��"+WHT+"�v"+NOR+", �²r�L�ܪ��A�X !",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
            "damage" : 500,
                "damage_type":  "�A��",
        ]),
        ([      "action":               "$N���x���M�x�X���, �K�V$n��$l!",
                "attact_type":  "wit",
            "damage" : 500,
                "damage_type":  "����",
        ]),
        ([      "action":               "$N���w���, "+HIR+"�u"+NOR+"�K���P�}"+HIR+"�v"+NOR+", ��X�ƹD����, ���s���_�����V$n��$l!",
                "attact_type":  "wit",
            "damage" : 500,
                "damage_type":  "���",
        ]),
    ([  "action":       "$N�o�Ʀ����N�@���״x��½, $n���צp�����, �@�ɤ������L��!",
                "attact_type":  "wit",
            "damage" : 500,
                "damage_type":  "�h�B����",
        ]),
    ([  "action":       "$N�j�ܤ@�n, �@��"+MAG+"�u"+NOR+"�۷����P"+MAG+"�v"+NOR+"�@�x�����L�۪���$n��$l���h!",
                "attact_type":  "wit",
            "damage" : 500,
                "damage_type":  "�h�B����",
        ]),
    ([  "action":       "$N�N���@�n, "+CYN+"�u"+NOR+"������P"+CYN+"�v"+NOR+"�@���ֳt���I�V$n��$l!",
                "attact_type":  "wit",
            "damage" : 500,
                "damage_type":  "�h�B����",
        ]),
    ([  "action":       "$N���@��, "+HIC+"�u"+NOR+"����P��"+HIC+"�v"+NOR+"���M�@�x��$n����ߥ��h!",
                "attact_type":  "wit",
            "damage" : 500,
                "damage_type":  "�h�B����",
        ]),
});

void do_clean();

void create()
{
        set_name(MAG"�f�P�Ѫ�"NOR,({"star old man", "old man","man" }) );
        set("long",@LONG
�L�O�ץͦu�@���į��q���u�q�H, �ǻ����ڥ����O�H, 
�۶Ǳq���q�X�{�}�l�L�N�X�{�F, �ӯ��q�b���m���w�g��
�@�d�G�ʦ~�����v�F....��....?!
LONG
);
        set("title",HIR"�u�u�q�̡v"NOR);
        set("age",1200+random(50));
        set("level",50);
        set("gender","�k��");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "�f�P�Ѫ̨�D�U�Q���إ����V�A....�C\n",
        "�f�P�Ѫ̨��W���M�o�X�@�}�H��...�C\n",
        }));
        set_skill("unarmed", 100);
      set("Merits/bar",7);
      set("Merits/sou",1);
      set("str",155);
    set("int",50);
          set("addition_armor",100);

    add("Merits/wit",8);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
      carry_object(__DIR__"eq/star_necklace.c")->wear();
        set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",

           HIW"\n�i�Q�U�j�s�j"+HIW"�ץͦu�q���f�P�Ѫ̳��M�Q"+ob->name(1)+"�����F..�o�N���ۤ���...?\n\n"+NOR,users());
            ob->add("popularity",3); //�n��
        ::die();
        return;
}

void init()
{
       add_action("typetake","take");
}
     int typetake(string arg)
{
        object me;
        me=this_player();
        message_vision("�f�P�Ѫ̧N�N������$N\n",me);
        message_vision("�f�P�Ѫ̻�������:�Q�ʳo�ӯ��q?...�� ...!\n",me);
        return 1;
}


