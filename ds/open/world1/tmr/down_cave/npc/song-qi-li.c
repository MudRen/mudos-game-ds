#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("���Y�F", ({ "song qi-li" ,"song","li" }) );
        set("long",@long
    ���Y�F���o�D�`�G�z�A���W��۪���A�n���u�]�ۤ@�����Y�����A
���L�������`�A�p���p�߾����L�[�A�n���|�Q�L�����믫�@�ˡC
long
);
        set_race("human");
        set("age", 30);
        set_stat_maximum("gin", 600);
        set_stat_maximum("hp", 600);
        set_attr("str",28);
        set_attr("cps",24);
        set_attr("cor",24);
        set_skill("blade",140 );
        set_skill("song blade" , 140 ); // ���a�M�k
        map_skill("blade","song blade");
        set_skill("parry",90);
        set_skill("dodge",90);
        set("attitude", "aggressive");
        set("title","�w�������Y��");
        setup();
        set_level(20);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
          carry_object(__DIR__"obj/memory_card3");
}


