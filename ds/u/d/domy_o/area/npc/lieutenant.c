#include <ansi.h>

inherit NPC;
void create()
{

        set_name( "�W�L", ({ "lieutenant","�W�L",}));
        set("long", "�@��A�q���x�R�O���~�C�W�L�C\n");
        set("level",100);
        set("title","�x�H");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 24);
        set("combat_exp",5000);         
        set("evil",20);
        set_skill("parry",50);                
        set_skill("gun",50);         
        set_skill("dodge",50);         
        set("attitude", "heroism");     
        set("creater","domy"); 
        set_leader("domy");
set("inquiry/domy", @LONG
  �L���b�V�O���{�N�ϰ�...���n�h�n�L...
LONG );


     set("chat_msg_combat", ({
(:command("kick "+this_player()->query("id")):),
 HIR"�W�L�j�s :�u�A�Q������?�y�ϧr�A!!�v\n"NOR,
     }) );

        setup();
}

