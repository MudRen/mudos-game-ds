
inherit NPC;

void create()
{
	set_name( "惡漢",({"bruiser"}));
	set("long","這個惡漢的面相十分恐怖，看來不好野的。");
	set("gender","男性");
	set("race","人類");
	set("level",14);
	set("age",30);
	set("evil",100);
	set("chat_chance",50);
	set("chat_msg",({
"惡漢突然回頭瞪你一眼\n"
"快滾~~這不是你來的地方\n"
}));
set("chat_chance_combat",60);
        set("chat_msg_combat", ({
        (:command("say 老子你也敢野?你活得不耐煩"):),
        }) );
	setup();
}
