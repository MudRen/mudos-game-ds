#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"九尾"NOR,({ "killer fox", "fox" }) );
        set("level",40);
        set("race", "野獸");
        set("age", 1000);
        set("title",HIR"殺人狐"NOR);
        set("long", "牠是這裡的頭頭, 據說牠已經活了上千年了。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
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
        if( ob ) message("world:world1:vision", HIC"\n  [小道消息]:"HIR"\n\n\t傳聞中的殺人狐  九尾如今竟慘死在"+ob->name(1)+"的手下!\n\n"+NOR,users());
        ob->add("popularity",1);
        message_vision( "$N"+HIR "臨死前，因為妖氣用盡，牙齒跟毛皮脫落下來...." NOR ,this_object() );
        ob->move(environment(this_object() ) );
        ob=new(__DIR__"obj/pe");
        ob->move(environment(this_object() ) );
        ::die();
        return;
}
