#include <ansi.h>
inherit NPC;
string *battlename = ({
	HIR+"�԰�����H"+NOR,
	HIW+"�԰�����H"+NOR,
	HIG+"�԰�����H"+NOR,
	HIC+"�԰�����H"+NOR,
	HIY+"�԰�����H"+NOR,
	HIM+"�԰�����H"+NOR,
	
void create()
{
	set_name(battlename[rando(sizeof(battlename))],({"battle droid","droid"}));
        set("long","�o�O�@�ӱM�ξ԰�������H�C\n");
        set("level",20);
        set("race", "�����H");
        set("combat_exp",4000);      
        set("evil",200);     
        set_skill("gun",45);   
        set_skill("parry",45);
      set_skill("unarmed",45); 	    
        set_skill("dodge",45);
set("chat_chance",60);
     set("chat_msg",({(: random_move :)}));    
   set("attitude", "aggressive");
/ set("chat_chance_combat", 100);
/     set("chat_msg_combat", ({
	        (:command("shoot"):),
		(:command("reload clip"):),
		(:command("say Roger......Roger......Roger"):),
       	 }) );
           setup();
	carry_object(/u/m/mulder/area/naboo/npc/wp/blaster")->wield();
	carry_object(/u/m/mulder/area/naboo/npc/wp/bclip");
	carry_object(/u/m/mulder/area/naboo/npc/wp/bclip");
	carry_object(/u/m/mulder/area/naboo/npc/wp/bclip");
	carry_object(/u/m/mulder/area/naboo/npc/wp/bclip");


}






