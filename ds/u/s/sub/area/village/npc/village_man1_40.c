inherit NPC;
void create()
{
        set_name("張炎", ({"MR. Cheng","mr","cheng"}) );
        set("long",@LONG
他是一位退休的公務人員，在幾年前妻子過逝以後，在他的臉上永遠隱
隱顯露出哀傷的表情。
LONG);
        set("gender","男性");        
        set("race", "human");
        set("age", 70);
        set("level",40);
        set("dex",30);
        set("talk_reply","別來煩我！本大爺心情不好，給我滾！\n");
        set("chat_chance",10);
        set("chat_msg",({
        (: command("say 唉！真煩......。\n", ):),
        (: command("say 我怎麼會這麼不小心呢！？\n"):),
        (: command("say 那麼貴重的東西......。\n"):),
        (: command("say 唉！早知道就不要去釣魚了。 \n"):),
        (: command("say 戴了那麼久的東西，掉了我竟然沒發現。\n"):),
        (: command("sigh"):),
        (: command("walk"):),
        }) );        
        setup();
}
