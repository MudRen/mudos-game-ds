#include <ansi.h>
inherit NPC;
mapping *combat_action = ({
        ([      "action":              "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIY+"���]�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�����{�L$n��$l!",

                "attact_type":  "sou",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
        ([      "action":               "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+MAG+"���\\�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�����{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
        ([      "action":               "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIR+"�}���Z"+NOR+""+CYN+"�j"+NOR+"�@�D�����{�L$n��$l!",

                "attact_type":  "sou",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIC+"�᧯�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ť��{�L$n��$l!",
                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIM+"����Z"+NOR+""+CYN+"�j"+NOR+"�@�D����{�L$n ��
$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+GRN+"�C��Z"+NOR+""+CYN+"�j"+NOR+"�@�D����{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIW+"�����Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ե��{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+WHT+"�|�ƳZ"+NOR+""+CYN+"�j"+NOR+"�@�D�ǥ��{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+YEL+"�a�g�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ť��{�L$n��$l!",

                "attact_type":  "bar",
            "damage" : 200,
              
  "damage_type":  "�`��",
        ]),
});

void create()
{
        set_name(CYN"���~"NOR,({"wo"}) );
        set("long",@LONG
�ڻ��e�O�̦��l�H�_�ٹP�J�·t�����~���@,�������~�S���Ӧh���O��.
LONG
);
        set("title",HIR"�u���P���šv"NOR);
        set("age",1000+random(50));
        set("level",60);
        set("gender","����");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "���~���M�Q�@�Ѥ����ҥ]��A�h�W���j�q�@�n.....�C\n",
        }));
        set("limbs", ({ "�Y��", "����", "�e��", "���", "����","���l" }) );
        set("verbs", ({ "bite", "claw" }) );
      set("str",120);
      set("int",50);
          set("addition_armor",100);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
        set("actions", (: call_other, __FILE__, "query_action" :));
    carry_object(__DIR__"eq/wo_waist")->wear();
    carry_object(__DIR__"eq/wo_cloak")->wear();
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
     message_vision("\n$N�������~�A�o��3�I�n��! \n",ob);
             ob->add("popularity",3); //�n��
        ::die();
        return;
}
