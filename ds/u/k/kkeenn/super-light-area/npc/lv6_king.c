#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N�r�M�ܨ�y�ʡI�z�A$n���������O�Q��F�@��",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "�Ƕ�",
        ]),
        ([      "action":               "$N�@�ۡy�Q��ⶳ�z��$n���a�豽�h�I",
                "attact_type":  "bar",
                "damage_type":  "����",
        ]),
     ([      "action":               "$N��M�V$n�Τ�o�X�@�D���O",
                "attact_type":  "bio",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N�B�Ω��O��$n�V�ἲ�h",
                "attact_type":  "bar",
                "damage_type":  "����",
        ]),
});

void do_clean();

void create()
{
     set_name(HIC"���E�g"NOR,({"gin kin","kin"}) );
        set("long",@LONG
�L�A�ǻ��������O����A��ƥ祿�稸�A���M��W���j�A���O�q�L��
�W���L�δ��o�X�𮧬ݨӡA�L�����O��⤤���j�٨Ӫ��F�`�H�I
LONG
);
        set("title","�y�g�H�z");
         set("age",80);
     set("level",60);
        set("gender","�k��");
       set("race","human");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "���E�g���|�P�T�_�F�z�}���n���H\n",
        "���E�g�ĤF�@�f��C\n",
        "���E�g�w�w���|�_��A����l���F�@���C\n",
        "���E�g���W�����O�C�C�����o�X�ӡC\n",
        }));
          set("addition_armor",100);
    set("Merits/wit",3);
        set("addition_damage",50);
        add("apply/hit",50);

        setup();
       carry_object(__DIR__"obj/g_plate.c");
        set("actions", (: call_other, __FILE__, "query_action" :));
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void init()
{
      ::init();
        add_action("do_guard", "go");
}
int do_guard(string arg)
{
        if( (arg!= "back") || !this_player()->visible(this_object()) ) return 0;
        write( name() + "��M�P��@�ѫl�����A�����L�h�I\n");
         command("smile");
           say("���E�g���D�G"HIB"�դU����J�_�w�A�ӪŤ�Ӧ^�O�H\n"NOR);
       return 1;
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
     message("world:world3:vision",
HIG"\n�i�y�H�S���j"+HIW"�y�H���ǻ�����-"HIC"���E�g"HIW"�Ѧb"+ob->name(1)+"����U�I�I\n\n"+NOR,users());
           ob->add("popularity",4);
        ::die();
        return;
}

