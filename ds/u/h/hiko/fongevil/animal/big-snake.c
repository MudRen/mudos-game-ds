#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���D",({ "big snake","snake" }) );
        set("level",22);
        set("race", "���~");
        set("age", 5);
        set("long", "�@���������������D�A�R�۬��������Y�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
void init()
{
        ::init();

if(userp(this_player() ) && this_object()->visible(this_player()))
  {
   message_vision("$N��q�@�n�A�}�l����$n�I�I\n",this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
        return;
}

