#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"�E��"NOR,({ "killer fox", "fox" }) );
        set("level",40);
        set("race", "���~");
        set("age", 1000);
        set("title",HIR"���H��"NOR);
        set("long", "�e�O�o�̪��Y�Y, �ڻ��e�w�g���F�W�d�~�F�C\n");
        set("limbs", ({ "�Y��", "����", "�e�}", "��}", "����" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_skill("dodge",100);
        set_skill("combat",100);
        set_skill("parry",90);
        add("addition_armor",90);
        add("addition_damage",80);
        set("evil",200);
        set("attitude", "aggressive");
        set("guild_gifts",({6,6,-2,10}));
        setup();
        carry_object(__DIR__"eq/fist2.c");
}
void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIC"\n  [�p�D����]:"HIR"\n\n\t�ǻD�������H��  �E���p�����G���b"+ob->name(1)+"����U!\n\n"+NOR,users());
        ob->add("popularity",1);
        message_vision( "$N"+HIR "�{���e�A�]������κɡA�������ֲ渨�U��...." NOR ,this_object() );
        ob->move(environment(this_object() ) );
        ob=new(__DIR__"obj/pe");
        ob->move(environment(this_object() ) );
        ::die();
        return;
}
