#include <npc.h>
inherit F_BANDIT;

void create()
{
        set_name("���s", ({ "song lian" ,"song","lian" }) );
        set("long",@long
�@�@���s�����ᰪ�A�����ۤ@�Ӱ�s�{�A�@����N���O�Ӱs��L�ת�
���~�k�H�C���L�N�w�������������Z�ޡu���a�M�k�v�f�t�ۤw���@�M
�B�k�A�ϥΰ_�ӭ��ٻ��¤O�C
long
);
        set_race("human");
        set("age", 40);
        set_stat_maximum("gin", 600);
        set_stat_maximum("hp", 600);
        set_attr("str",28);
        set_attr("cps",24);
        set_attr("cor",24);
        set_skill("blade",120 );
        set_skill("song blade" , 120 ); // ���a�M�k
        map_skill("blade","song blade");
        set_skill("parry",80);
        set_skill("dodge",80);
        set("attitude", "aggressive");
        set("title","�w�������Y��");
        setup();
        set_level(20);
        do_heal();
        carry_object(__DIR__"obj/blade")->wield();
        carry_object(__DIR__"obj/yellow-cap")->wear();
        carry_object(__DIR__"obj/portable-boots")->wear();
          carry_object(__DIR__"obj/memory_card1");
}

