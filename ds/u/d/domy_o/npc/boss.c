#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"�d�Ѥj"NOR,({"fire chicken","fire"}));
        set("level",70);
        set("str", 100);
        set("evil",100);
        set("ap",20000);
        set("mp",20000);
        set("combat_exp",59000);
        set("age",random(9)+33);
        set("long", "�ݰ_�ӫܥ������y�]�A���N�O�s�����C\n"
        );
        set("chat_chance_combat",120);
        set("chat_msg_combat",({
                                (:command("reload clip"):),
                                (:command("exert doubleshoot"):),
                                (:command("exert moon_force recover"):),
                                (:command("cast god-benison"):),
                                (:command("shoot"):),
                                (:command("cast god-fire"):),
}));


        set("class","fighter");
        set("class1","�x�H");
        set("title","�T�q��");
        set("nickname",HIR"�s����"NOR);
        set("flurrydodge",1);
        set_spell("god-fire",100);
        set_spell("god-benison",100);
        set_skill("unarmed",70+random(10));
        set_spell("summon_ghost",100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("combat",100);
        set_skill("gun",100);
        set_skill("force", 100);
        set_skill("moon_force",100);
        set_skill("fogseven",100);
        map_skill("sword","sorgi_sword");
        map_skill("force","moon_force");
        map_skill("dodge","fogseven");

       setup();
        carry_object(__DIR__"wp/65k2")->wield();
        carry_object(__DIR__"wp/middle_clip");
        carry_object(__DIR__"wp/middle_clip");
        carry_object(__DIR__"wp/middle_clip");
        carry_object(__DIR__"wp/middle_clip");
}
void init()
 {
        object leader;
        if( objectp( leader = find_living("domy") ) )
        {
                set("creater",leader);
                set_leader(leader);
                return;
        }
        ::init();
}

