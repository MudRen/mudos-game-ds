// 1999.12.10 修改 by Luky
inherit NPC;

void create()
{
	set_name("傲過",({"aw-kore","kore"}) );
	set("long",
"你眼前一亮，不禁被這位身著白衣，美皙如玉，風度翩翩的瀟灑男子\n"
"所吸引住，只見他一臉憂鬱，不時地嘆氣，似乎正為什麼事在煩腦。細看\n"
"其衣裳左胸前畫有七朵梅花，另有紫白青金四線為底。渾身英氣十足，神\n"
"采曄然，一眼便得知其武術造詣之高。\n"
);
	set("age",33);
	set("race","人類");
	set("level",30);
            set("attitude", "peaceful");
            set("title","【傲梅派】第四代弟子");
           set("gender", "男性" );
	set("chat_chance",6);
	set("chat_msg",({
	"傲過喃喃自語地說道：前些日子真不小心，怎會爛醉如泥，以致被無知宵小行竊..\n",
	(:command("sigh"):),		
	"傲過喃喃自語地說道：不知那東西去向如何，我要怎麼和莊主交待呢....\n"
	}) );

      set_skill("unarmed",80);
	set_skill("sword",70);
	set_skill("force",80);
         set_skill("awmay-ken",80);
         map_skill("unarmed","awmay-ken");

	setup();
        carry_object(__DIR__"wp/suisword")->wield();
}
//luky fixed 1999/7/30
int accept_object(object who,object ob)
{
	object pill;

	if(ob->name()!="金牌") 	return 0;
	else {
		
	  if(this_object()->query_temp("give_pill")) 
	  {
	    command("say 我的金牌已經找回來了.. 怎麼你還有一面金牌?");
	    command("? "+who->query("id"));
	    command("say 你還是自己留著吧...");
	    return 0;
	  }
	  
      message_vision("$N給了傲過一面$n。\n",who,ob);
	destruct(ob);
	command("say 這可是我那遺失的金牌！！這.....這...");
	command("thank "+who->query("id"));
	command("say 此恩此德，傲某無以回報，傲某身上有幾粒靈丹，就送給恩公吧。");
	pill=new(__DIR__"obj/stream");
	pill->move(who);
	pill=new(__DIR__"obj/stream");
	pill->move(who);
	set("chat_msg",({
	"傲過喃喃自語地說道：還好，金牌終於拿回來了..\n",
	(:command("idle"):),		
	}) );
	set_temp("give_pill",1);
//	call_out("delay",600,this_object());
	return 1;
	}

}

int talk_action(object me)      //talk 時會執行此函式.
{
 if(this_object()->query_temp("give_pill")) command("say 小弟掉的東西已經找回來了，多謝關心。");
 else
 {
 	switch(random(3))
 	{
 		case 0:	command("say 請問閣下可否見過一面金牌?");
 			break;
 		case 1:	command("say 唉.. 一切都是小弟的疏忽，實在不足為外人道。");
 			break;
 		case 2:
 		default:
 			command("say 那麼重要的金牌..唉..都怪我一時貪杯..");
 			break;
 	}
 }
 return 1;
}


void reset()
{
//	if(!kore) return;
	delete_temp("give_pill");
	set("chat_msg",({
	"傲過喃喃自語地說道：前些日子真不小心，怎會爛醉如泥，以致被無知宵小行竊..\n",
	(:command("sigh"):),		
	"傲過喃喃自語地說道：不知那東西去向如何，我要怎麼和莊主交待呢....\n"
	}) );
	return;
}
