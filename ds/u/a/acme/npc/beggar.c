#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "老乞丐", ({ "old beggar","beggar" }) );
        set("level",45);
        set("gender","男性");
        set("combat_exp",4500);
        set("long" ,"他是白髯至胸且年事已高的老乞丐，衣衫襤褸的頹坐在地上。\n");
        set("age",80);
        set("evil",-40);
        set_skill("unarmed",100);
     set_skill("sword",100);
     set_skill("force",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set("chat_chance", 15);
        set("chat_msg", ({
        }) );
        set("inquiry/劍", "咦！？論天下之劍：\n"
                          "            第七懾日、第六忘魂、\n"
                          "            第五逍遙、第四紅塵、\n"
                          "            第三達摩、第二無名。\n"
                          "老乞丐說道：這些劍可是武林高手互相爭奪，欲求不可得的神兵利器呀。\n",
           );
        set("inquiry/第一", "這…這…嘿！嘿！\n");
        set("inquiry/第一劍","這…這…嘿！嘿！\n");
        setup();
}
