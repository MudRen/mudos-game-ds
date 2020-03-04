
inherit NPC;

void create()
{
	set_name("賭客",({ "ringman","man" }) );
	set("long",
	"一個穿著破布衣破鞋的人，正眼巴巴注視著碗中滾動的骰子，看來九\n"
	"成是個好賭成性的傢伙。\n"
	);

	set("race","人類");
	set("gender","男性");
	set("chat_chance",3);

	set("chat_msg",({
	"賭客喃喃自語地說道：「再玩最後一把就好，一定要要把之前輸的全贏回來才行。」\n",
	(:command("sigh"):),
	"賭客對著碗中尚在滾動的骰子，不停地喊道：「十八啦∼∼」\n",
	}) );
	set("age",30);
	set("level",4);
        set("attitude", "heroism");  

	setup();
        add_money("coin",200);
}
