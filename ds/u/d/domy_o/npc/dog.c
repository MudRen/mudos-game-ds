#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIM"�ƪ�"NOR,({"cry dog","dog"}));
        set("level",70);
        set("str", 100);
        set("evil",100);
        set("ap",20000);
        set("mp",20000);
        set("combat_exp",-1000);
        set("age",40);
        set("long", "�ݰ_�ӫܥ������y�]�A���N�O�ƪ��C\n"
        );

        set("chat_chance_combat",120);
        set("chat_msg_combat",({
                                (:command("exert thundersword"):),
                                (:command("exert moon_force recover"):),
                                (:command("cast god-benison"):),
                                (:command("cast god-fire"):),
}));
        set("title",CYN"�T�q���Q���D"NOR);
        set("nickname",YEL"��������"NOR);
        set("flurrydodge",1);
        set("attitude", "aggressive");
        set_spell("god-fire",100);
        set_spell("god-benison",100);
        set_skill("unarmed",70+random(10));
        set_spell("summon_ghost",100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("combat",100);
        set_skill("sorgi_sword",100);
        set_skill("force", 100);
        set_skill("moon_force",100);
        set_skill("fogseven",100);
        map_skill("sword","sorgi_sword");
        map_skill("force","moon_force");
        map_skill("dodge","fogseven");

        setup();
        carry_object(__DIR__"wp/sword")->wield();
}


