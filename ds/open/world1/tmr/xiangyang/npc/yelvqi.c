// yelvqi.c �C�߻�

#include <ansi.h>

inherit NPC;
inherit F_SKILL;

void create()
{
        set_name("�C�߻�", ({ "Yelv qi", "yelv", "qi" }));
        set("title", "���u�вĤG�N�̤l �����ĤG�Q�@�N���D");
        set("gender", "�k��");
        set("age", 25);
        set("per", 25);
        set("long",
        "���t�M���T���j�k�B�A���ܪ��V�ҡC\n",);

        set("combat_exp", 600000);
        set("shen_type", 1);

        set("max_neili", 2000);
        set("neili", 2000);
        set("jiali", 0);

        set_skill("force", 100);
        set_skill("sword", 100);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("hubo" ,100);
        set_skill("haotian-zhang" ,100);
        set_skill("quanzhen-jian" ,100);
        set_skill("kongming-quan",200);
        map_skill("unarmed","kongming-quan");
        map_skill("strike","haotian-zhang");
        map_skill("sword","quanzhen-jian");
        map_skill("parry","quanzhen-jian");

        create_family("���u��", 2, "�̤l");
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}
