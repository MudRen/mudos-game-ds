#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("����", ({ "song zhong" ,"song","zhong" }) );
        set("long",@long
�@�@���׬O�@�Ӻ��y��ת����Ӥj�~�A�G�Ӳ����@�Ӥj�@�Ӥp�A���
�ۭ��A���ۦ��I�Τj���{�l�A���O�q�L���u�W�o�F���٦שM�p�ꪺ��
���ݨӡA�ˤ]�������H�p��L�C
long
);
        set_race("human");
        set("age", 40);
        set_stat_maximum("gin", 400);
        set_stat_maximum("hp", 400);
        set_attr("str",24);
        set_attr("cps",17);
                set_attr("cor",22);
                set_skill("blade",60);
                set_skill("parry",60);
                set_skill("dodge",60);
        set("attitude", "aggressive");
        set("title","�w�����p�Y��");
        setup();
		set_level(15);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
         carry_object(__DIR__"obj/yellow-cap")->wear();
           carry_object(__DIR__"obj/portable-boots")->wear();
}



