inherit NPC;

void create()
{
	set_name("廚師", ({"chef"}) );
	set("long", @LONG
    你眼前這個正在切菜的廚師是個來自羅慕倫星的羅幕倫人，據聞
個性多變，一分鐘前可能還很溫和，一分鐘後可能就會翻臉。他手上
的肉類切割器細長而尖銳，還染滿了血跡。
LONG
);
	set("race", "人類");
	set("age", 40);
	set("level", 19);
        set("attitude","killer");
        set("chat_chance", 5);
        set("chat_msg", ({
       (: command("eh") :),
       (: command("say 找死嗎!?小子!?") :),
}));
	setup();
	carry_object(__DIR__"wp/Wp1.c")->wield();
}
