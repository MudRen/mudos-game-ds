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
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIM+"����Z"+NOR+""+CYN+"�j"+NOR+"�@�D����{�L$n ��$l!",

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

void do_clean();

void create()
{
        set_name(WHT"�����t�D"NOR,({"cloudwind taoist", "cloudwind","taoist" }) );
        set("long",@LONG
�L�O�u�@�o�ӯ������D���D�H, �ǻ��L�q���q�Щl�N�b
�F, �ӯ��q�O�b�@�d��ʦ~�e�Ыت�, ���L���D�w�g....?
���L�q�L�O�����A�רӬ�, �u�O�Mħ�i�˰�!....
LONG
);
        set("title",MAG"�u���|�̡v"NOR);
        set("age",1200+random(50));
        set("level",50);
        set("gender","�k��");
 set("attitude", "peaceful");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "�����t�D�O�����������F�_��...�C\n",
        "�����t�D�Mħ����ۧA....�C\n",
        }));
        set_skill("unarmed", 100);
      set("Merits/sou",6);
      set("int",175);
          set("addition_armor",100);
    set("Merits/wit",3);
        set("addition_damage",50);
      set("no_busy",1);
        add("apply/hit",50);
        setup();
    carry_object(__DIR__"eq/wind_leg")->wear();
        set("actions", (: call_other, __FILE__, "query_action" :));
}

int talk_action(object me)        
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 {
 command("smile "+me->query("id") );
        command("say �ڬO�o�ӯ��q������A�o�ӯ����èS������ȱo�@�ݪ��a��...");
        command("say �p�G�A�O�@�۪��Ю{�A�N�h����(pray)���ӻ����a~");
        command("say ���L�d�U�n�V���M�w...���̥i�����ܭ�!");
}
 return 1;
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

           HIR"\n�i�Q�U�j�s�j"+MAG"��j�������t�D���M�Q"+ob->name(1)+"�R���F, ���D�Q�U�j�s���ʦL...?\n\n"+NOR,users());
            ob->add("popularity",3); //�n��
        ::die();
        return;
}


