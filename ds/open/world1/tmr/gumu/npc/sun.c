// sun.c �]�C�C

// 1998.9 by Lgg

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�]�C�C", ({"sun popo", "sun"}));
        set("gender", "�k��");
        set("age", 55);
        set("long",
                "�o�O�@��O�����ѱC�C�A���ݵۧA�L�L�@���C\n"
        );
        set("attitude", "friendly");
        set("level",20);
        set_skill("whip", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("unarmed",60);
        set_skill("literate",60);


        set("inquiry", ([
                "�p�s�k" : "�s�h�Q�O�ڤ@��a�j���A�o�q�p�S�F�����A�{�b�S�W�Ө��b�o�j�Ө��A��..\n",
        ]) );

        setup();
        carry_object(__DIR__"obj/yinsuo.c")->wield();
        carry_object(__DIR__"../obj/goldkey.c");
}


