// 老人 2 : 扯上軒轅烈 ( 洪怨桓 )

#include <ansi.h>
inherit NPC;

string *lieh = ({
	YEL"洪怨桓說﹕什麼？你說什麼呀, 廣老頭.......？\n"NOR,
	"",
	YEL"洪怨桓似乎想到了什麼, 有點婉惜說﹕那個咺元列？好像是軒轅劣吧？\n"NOR,
	YEL"洪怨桓說﹕前幾年他迷路在山下的森林中...\n"NOR,
	"","",
	YEL"洪怨桓說﹕我們這幾個老頭, 看他是可造之才, 就救了上來...\n"NOR,
	YEL"洪怨桓說﹕後來又授他幾招武術, 不料, 後來幾個衙門的人找上來了, 只好讓那些人帶他走了...\n"NOR,
	"",
	YEL"洪怨桓說﹕臨走前, 咱們決定好了, 將畢生所研習的幾招絕技, 寫在一本"HIY"冊子"NOR+YEL"上, 塞給了他, ...\n"NOR,
	"","",
	YEL"洪怨桓說﹕至今, 仍未有他的消息, 可就苦了周進山這老頭了...\n"NOR,
	GRN"洪怨桓帶有點生氣說﹕他為了找那小夥子, 而下山去衙門尋他, 反遭一個可惡的捕快痛打了一頓,...\n"NOR,
	"",
	GRN"洪怨桓說到這裡, 臉上露出一股生氣的表情。\n"NOR,
	"","",
	YEL"洪怨桓說﹕你看看老周的樣子, 就知道那個捕快多狠心......\n"NOR,
	YEL"洪怨桓似乎不再多言, 嘆了嘆幾口氣, 又安靜了下來...\n"NOR,
});

string run(object me);

string *msg_dunno = ({
	"沒聽說過。\n",
	"無可奉告。\n",
	"嗯....這我可不清楚﹐你最好問問別人吧。\n",
	"對不起﹐你問的事我實在沒有印象。\n"
});

void create()
{
	set_name( "洪怨桓", ({"yuann-hwan horng", "horng", "yuann", "hwan", "yuann-hwan" }) );
	set("long", @LONG
一位身形憔悴的老人，但是臉上的神色卻很紅潤。
LONG	);

	set("title", HIM"紫陽四隱 - 洪"NOR);
	set("gender", "男姓");
	set("race", "人類");
	set("age", 80+random(30));
	set("level",40);
	set("evil",20+random(20));
	set("attitude", "heroism" );

	set_skill("dodge", 70+random(10));
	set_skill("parry", 50+random(20));
	set_skill("unarmed", 65+random(30));
	set_skill("sword", 78);
	set_skill("force", 100);
	set_skill("sorgi_sword", 75);
	set_skill("moon_force", 70);

	map_skill("force","moon_force");
	map_skill("sword","sorgi_sword");

	set("chat_chance", 3);
	set("chat_msg", ({
  (: command,"sigh" :),
}));
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
  (: command,"exert moon_force recover" :),
  (: command,"angry" :),
  (: command,"say 真他奶奶的, 連老人都趕欺負..":),
}));
	set("inquiry", ([
  "冊子" : (: run :),
]));
	setup();
	carry_object(__DIR__"wp/old_long_sword.c")->wield();
	carry_object(__DIR__"eq/slipshod_cloth.c")->wear();
	carry_object(__DIR__"eq/slipshod_boots.c")->wear();
}

void lieh(object who,int flag)
{
        if( !who ) return;
	message_vision(lieh[flag], this_object());
	
	if( ++flag < sizeof(lieh) )
	{
		call_out("lieh", 1, who, flag );
		return;
	} 
	tell_object(who, HIC" 或許\你可以問問看 周進山 一些問題, 或者再問問 洪怨桓 一些問題. \n"NOR);
	return;
}

int accept_object(object who, object ob)
{
	if( !ob->id("wu_lin_me_gei") ) return 0;
	command("thank " + who->query("id"));
	message_vision("$N跟周進山, 江樂勝, 廣自成討論了一下.. \n", this_object());
	command("say "+ RANK_D->query_respect(who) + "想要學學武功\嗎？");
	who->set("quest/wind_adv", 1);
	who->set_temp("class_wind/join_adv", 1);
	return 1;
}

void init()
{
	add_action("do_say", "say");
}

int do_say(string arg)
{
	object me = this_player();
	if( arg != "好" && arg != "要" && arg != "想" && !me->query_temp("class_wind/join_adv") )
		return 0;
	message_vision(YEL"$N說："+arg+NOR+"\n" , me);
	me->delete_temp("class_wind/join_adv");
	call_out("say_yes", 2, me);
	return 1;
}

void say_yes(object me)
{
	object jiang;
	jiang = present("yuen-shan jiang", environment(this_object()));
	message_vision(GRN"$N稍微沉吟了一下.....\n"NOR, this_object());
	if( me->query("level") == 25 && me->query("class2")!="疾風門" && me->query("class1")=="疾風門" )
		command("say " + RANK_D->query_respect(me) + ", 你跟江老頭拿個東西, 去找小夥子去, 他自會有打算的... ");
	command("say 喂！老江, 拿那個東西給這" + RANK_D->query_respect(me) + "吧！");
	if( objectp(jiang) ) jiang->take_thing_a(me);
}

string run(object me)
{
	me = this_player();
	if( me->query_temp("book") && me->query("class1") == "疾風門" )
		return "那是一本小冊子, 記有我們的許\多招式, 若你能幫咱老頭找回來, 將以傳功\於你... \n"BLU"　　　　　　(或許\可以去找找看疾風門！)\n";
	else if ( me->query_temp("book") )
		return "那是一本小冊子, 記有我們的許\多招式, 你不是疾風一派的, 我也不便多說, 洪某雖是糟老頭子也不會把本派秘密亂講的。\n"BLU"　　　　　　(或許\可以去找找看疾風門！)\n";

	else return msg_dunno[random(sizeof(msg_dunno))];
}
