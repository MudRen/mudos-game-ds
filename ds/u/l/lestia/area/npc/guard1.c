#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�Ю{", ({ "guard"}) );
     set("nickname", HIC"�F�۱Цu��"NOR);
        set("long","�@�ӥ��`�b�j�������ˬd�q�U�a�ӨӪ��H���W�O�_�a���M�I���㪺�H�C\n");
        set("level",30);
        set("age",40+random(3));
        set("combat_exp", 29000);
        set("chat_chance", 4);
        set("chat_msg", ({
        (: command,"peer" :),
        "�Ю{��: �A���ˬd�L�F�ܡH\n",
}));
        set("inquiry",([
"�i�J" : "�A�n�i�J�H���̥i���O�L�H���H�K�i�J����C\n",
]));

        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
        HIW"�Ю{�V�̭��j��:�u���H�n���i�ӤF�I�v\n"NOR
}));
        set_skill("sword", 60);
        set_skill("parry", 70);
        set_skill("unarmed", 76);
        set_skill("dodge", 65);
        setup();
//        carry_object(__DIR__"wp/longsword")->wield();
//        carry_object(__DIR__"eq/boots")->wear();
}

