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

                "attact_type":  "wit",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
        ([      "action":               "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIR+"�}���Z"+NOR+""+CYN+"�j"+NOR+"�@�D�����{�L$n��$l!",

                "attact_type":  "sou",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIC+"�᧯�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ť��{�L$n��$l!",
                "attact_type":  "wit",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIM+"����Z"+NOR+""+CYN+"�j"+NOR+"�@�D����{�L$n ��$l!",

                "attact_type":  "wit",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":       "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+GRN+"�C��Z"+NOR+""+CYN+"�j"+NOR+"�@�D����{�L$n��$l!",

                "attact_type":  "wit",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+HIW+"�����Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ե��{�L$n��$l!",

                "attact_type":  "wit",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+WHT+"�|�ƳZ"+NOR+""+CYN+"�j"+NOR+"�@�D�ǥ��{�L$n��$l!",

                "attact_type":  "wit",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
    ([  "action":      "$N�f�����ۻy,�E���ѩG�� "+CYN+"�i"+NOR+""+YEL+"�a�g�Z"+NOR+""+CYN+"�j"+NOR+"�@�D�ť��{�L$n��$l!",

                "attact_type":  "wit",
            "damage" : 200,
                "damage_type":  "�`��",
        ]),
});

void do_clean();

void create()
{
        set_name(WHT"���C��"NOR,({"roam monk", "monk"}) );
        set("long",@LONG
���C���ӥ|�B���C�����C���A���L�L�b�o�̷F����O�C
LONG
);
        set("title",CYN"�u�ǻ��̡v"NOR);
        set("age",1200+random(50));
        set("level",50);
         set("race","tiger");
        set("gender","�k��");
 set("attitude", "peaceful");
        set("chat_chance", 30);
        set("chat_msg",({ 
        "���C�����H�����ݵۧA....�C\n",
        "���C���ݧA�D: �]�a���Ӫ�?�C\n",
        }));
        set_skill("staff", 100);
       set("Merits/sou",4);
       set("Merits/wit",3);
       set("addition_armor",100);
       set("addition_damage",50);
       add("apply/hit",50);
        setup();
       carry_object(__DIR__"eq/world_staff")->wield();
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

           HIR"\n�i�Q�U�j�s�j"+MAG"���C���{���e�I�۹D�G�f�P�D��...�ѤU�Ӫ��N���浹�A�F.....\n\n"+NOR,users());
            ob->add("popularity",3); //�n��
        ::die();
        return;
}


int accept_object(object who,object ob)
{
                object obj,me;
                obj=this_object();
                me=this_player();
                if(ob->name()!="�C��O")
                {
                 command("? "+who->query("id"));
                 return 0;
                }

                if(obj->is_busy() || obj->is_fighting())
                {
                 command("whisper "+who->query("id")+" ��...�i�H�F�C");
                 return 0;
                }
                message_vision("$N���F���C���@��"+ob->query("name")+"�C\n",who);
                message_vision("���C����$N���D: �i�H�F..�L�h�a�C\n",who);   
                message_vision("���C�����M�B�_�x�O, �N$N���V�s�y�U!!\n",who); 
                 destruct(ob);
                 me->move("/open/world1/faceoff/sky/ten39");
                 return 1;
}

