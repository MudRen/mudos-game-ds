#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���~" , ({ "monster beasts", "beasts", "__GUARD__" }) );
        set("level",10);
       set("gender","�L��");
        set("age",10);
           set("combat_exp",1000);
        set("race","���~");
           set("attitude","killer");
       set("evil",20);
        set("long","�o�O�@�����o�ǲ������~�A���ͻH�A���|�ϡA�����ڡA�����L�A���������Ǫ��C\n");
        set("limbs", ({ "�Y��", "����", "�ͻH", "����","��","�e�}","��}" }) );
        set("verbs", ({ "claw", "poke","hoof","crash","bite" }) );
        setup();
}
