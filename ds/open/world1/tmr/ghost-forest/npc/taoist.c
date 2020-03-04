inherit NPC;

void create()
{
	set_name("無名道人",({"taoist"}) );
	set("long",@LONG
一個身作道士打扮模樣的人，散發著一股濃濃的酒味，看他醉眼惺忪
，身著的道服盡是油膩不堪，嘴裡兀自唱著不知名的小調，一眼便知是個
酒肉道人。
LONG
);
	set("age",40);
	set("race","人類");
	set("level",15);
        set("attitude", "peaceful");
        set("gender", "男性" );
	set("chat_chance",10);
	set("chat_msg",({
	"道人嘆道：秋老頭的百花釀真乃酒中極品，光是那酒香就夠醉死人了....\n",
	(:command("lick"):),
	"道人東搖西晃地說道：酒...酒....我還要痛快喝上他三天三夜...\n",
	}) );

	set_skill("parry",40);
	set_skill("dodge",40);
	set_skill("unarmed",40);

	setup();
	carry_object(__DIR__"obj/seal");
	carry_object(__DIR__"eq/shoe")->wear();
}

int accept_object(object who,object ob)
{
        object seal;
        seal=new(__DIR__"obj/seal");

        if(ob->name()!="百花釀")
	{
		command("say 咦！你給我這個做啥？");	
        	return 0;
	}
        else {
		command("say 這可不是秋老頭的「百花釀」嘛...");
		command("lick");
		command("say 可真是謝謝你了，這張符咒就送你吧。");
		seal->move(who);
		destruct(ob);
	        return 1;
        }

}

