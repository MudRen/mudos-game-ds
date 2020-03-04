#include <ansi.h>
inherit NPC;

void create()
{
//=========================�򥻳]�w==========================
        set_name( "�b�H�T", ({ "halfshark",}));
        set("level",45);
        set("title","[1;32m����[m");
        set("race", "���~");
        set("age", 42);
        set("evil",45);
        set("war",1);
        set_skill("spear",250);
        set_skill("rapid",120);
        set("coin", random(300));
        set("long", @LONG
�@���H���T�����b�H��, �@�f�U�Q�������ݰ_�ӤQ�����ݡC
LONG
        );

//========================�A�����O=================================
   set("attitude", "aggressive");    //�^���D�q�� NPC�C

//=============================�۰ʰʧ@=================================
set("chat_chance", 50 );  //�ʧ@���v
set("chat_msg", ({       //�ʧ@���e
(:command("go east"):),
(:command("go west"):),
(:command("go north"):),
(:command("go south"):),
(:command("go down"):),
(:command("go up"):),
}) );

set("chat_chance_combat", 20);
set("chat_msg_combat", ({
(:command("rapid"):),
(:command("go east"):),
(:command("go west"):),
(:command("go north"):),
(:command("rapid"):),
(:command("go south"):),
(:command("go out"):),
(:command("go enter"):),
(:command("rapid"):),
(:command("go down"):),
(:command("go out"):),
(:command("go up"):),
}) );
set("limbs", ({ "�Y��", "����", "�e�}", "��}","����"})); //���𳡦�
set("verbs", ({ "bite","claw"})); //�������A��hoof��crash�rbite��claw��poke
 setup();
//==========================�˳ƹD��=============================
//      carry_object(__DIR__"item/bag");
      carry_object(__DIR__"wp/blackspear")->wield();
//      carry_object(__DIR__"eq/blackjacket")->wear();
}

void init()
{
 object npc, me;
 me=this_player();
 if(!me) return;
 if(this_object()->is_fighting()) return;
 this_object()->remove_all_killer();
 if(me==this_object()) return;
 if(me)
  if(!userp(me))
 { 
 if(npc=present("jailor",environment(this_object()))) kill_ob(npc);
 if(npc=present("dracion",environment(this_object()))) kill_ob(npc);
 if(npc=present("rtmwu",environment(this_object()))) kill_ob(npc);
 if(npc=present("dwarf",environment(this_object()))) kill_ob(npc);
 if(npc=present("troll",environment(this_object()))) kill_ob(npc);
 if(npc=present("pedestrian",environment(this_object()))) kill_ob(npc);
 if(npc=present("mother",environment(this_object()))) kill_ob(npc);
 if(npc=present("child",environment(this_object()))) kill_ob(npc);
 if(npc=present("flaw",environment(this_object()))) kill_ob(npc);
 if(npc=present("nanie",environment(this_object()))) kill_ob(npc);
 if(npc=present("master",environment(this_object()))) kill_ob(npc);
 if(npc=present("father",environment(this_object()))) kill_ob(npc);
 if(npc=present("sweeper",environment(this_object()))) kill_ob(npc);
 if(npc=present("kid",environment(this_object()))) kill_ob(npc);
 if(npc=present("pupil",environment(this_object()))) kill_ob(npc);
 } else  kill_ob(me);
}
