#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;
inherit F_VENDOR;

int pill_total=10;
void do_eat_pill()
{
        object ob=this_object();
        if(ob->is_busy()) return;
        if(pill_total==0) return;
        if(ob->query_stat("hp")<ob->query_stat_maximum("hp") ) {
                message_vision(HIG"$N���t�a�q�h�����F���ĤY�]�F�U�h...\n"NOR,ob);
                pill_total--;

                do_heal();
        }
}
void create()
{
    set_name("�B�C�s", ({ "bu qing shan","bu","shan"}) );

    set_race("human");
    set_skill("parry", 50);
    set_skill("unarmed", 50);
    set_skill("dodge", 50);
    set_skill("whip",80);

    set("title","�p�]���");
    set("age",30);
    set("long",@long
�B�C�s�O�o�����g�ͤg������͡A�]�O�ߤ@���@����͡A�өʨ}���n
�I�A�C��������j�p�f�h�ɡA�L�`�O�Ĥ@�ӻ���Ϫv�A�D�`���j�a���R��
�A�n�O�A���F����ˡA�ˤ����i�H���L��v�C
long
);
    set("chat_chance", 5);
    set("chat_msg", ({
        "�B�C�s�����ۤ�f�ۤ@�ӧ������߻K�W�A�������Eť��......\n",
        "�B�C�s�q������d�����X�F�X���ġA��ݤF�Ӭݯf�������X�y...\n",
        "�B�C�s��F�A�@���A�S��^�h���L�ۤw���ƤF�C\n",
   }));
        set("merchandise", ([
                "/d/obj/drug/fengwei-herb": 30,
        ]));
    set("chat_chance_combat", 5);
    set("chat_msg_combat", ({
        (: do_eat_pill :),      // �԰����Y�ĸɦ�..
    }));

    setup();
    set_level(15);
          carry_object(__DIR__"obj/large-fengwei-herb");
        carry_object(__DIR__"obj/white-jade-ring")->wear();
          carry_object("/d/obj/shortwhip")->wield();

}
void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}


int accept_fight(object ob)
{
        return 1;
}


