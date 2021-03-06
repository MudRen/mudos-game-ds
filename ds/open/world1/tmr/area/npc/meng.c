#include <net/dns.h>
inherit NPC;

int WWWW=0;
string arg;
void do_teach();

void create()
{
        set_name("孟秋農",({"meng chiou nong","meng"}) );
	set("long",
	"一個年約七十歲的長身白髮老翁，穿著樸實平常，一臉和善，雖已入\n"
	"古稀之年，但精神抖擻，絲毫不見老態。孟秋農熟讀詩書，常常教導村民們\n"
    "讀書識字，他的居所儼然已成了間私塾。如你也想多讀點書，不妨坐下來，\n"
	"和大家一起讀書。\n"
        );
        set("title","村長");
        set("age",70);
        set("level",10);
        set("gender","男");
        set("race","人類");
        set("chat_chance",10);

        set("chat_msg",({
		(:do_teach:),
		(:do_teach:),
		"孟秋農打了個哈欠..「ㄟ..我講到哪裡了?..讓我想想..」\n",
		(:do_teach:),
		"孟秋農點了點頭，並且走了幾步。\n",
		(:do_teach:),
        }) );	

        set_skill("unarmed",20);
        set_skill("parry",20);
        set_skill("dodge",20);
        set_skill("bagi_fist",10);
        map_skill("unarmed","bagi_fist");
        setup();
        add_money("silver",5);
}

void do_teach()
{
	object ob,*s;
	
	int j;
	arg="請先生教誨";
	ob=this_object();

	if(ob->is_fighting() ) return;
	
	switch(WWWW)
	{
	
	case 1:
		command("say 動靜有常，剛柔斷矣。");
		arg="動靜有常，剛柔斷矣。";
	break;

	case 2:
		command("say 方以類聚，物以群分，吉兇生矣。");
		arg="方以類聚，物以群分，吉兇生矣。";

	break;

	case 3:
		command("say 在天成象，在地成形，變化見矣。");
		arg="在天成象，在地成形，變化見矣。";
	break;
	case 4:
		command("say 是故，剛柔相摩，八卦相蕩。");
		arg="是故，剛柔相摩，八卦相蕩。";
	break;
	case 5:
		command("say 鼓之以雷霆，潤之以風雨。");
		arg="鼓之以雷霆，潤之以風雨。";
	break;
	case 6:
		command("say 日月運行，一寒一暑，乾道成男，坤道成女。");
		arg="日月運行，一寒一暑，乾道成男，坤道成女。";
	break;
	case 7:
		command("say 乾知大始，坤作萬物，乾以易知，坤以簡能。");
		arg="乾知大始，坤作萬物，乾以易知，坤以簡能。";
	break;
	case 8:
		command("say 易知則有親，易從則有功\。");
		arg="易知則有親，易從則有功\。";
	break;
	case 9:
		command("say 有親則可久，有功\則可大。");
		arg="有親則可久，有功\則可大。";
	break;
	case 10:
		command("say 教了一段，系辭傳博大精深，恐怕你們記不住，我再重講一次吧。");
		WWWW=-1;
	break;
	default:
		command("say 天尊地卑，乾坤定矣。卑高以陳，貴賤位矣。");
		arg="天尊地卑，乾坤定矣。卑高以陳，貴賤位矣";
		break;
	}

	WWWW++;

	s = all_inventory(environment(this_object()));
	if(sizeof(s)<1) return;
	for(j=0;j<sizeof(s);j++)
	{
		if(userp(s[j]) && s[j]->query_temp("do_sit") && arg)
		{
                if( s[j]->query_temp("netdead") == 1 ) continue;
                // 斷線的人不能跟著讀書...add by -Acme-
			message_vision("$N跟著念道："+arg+"\n",s[j] );
          		if (s[j]->query_skill("literate",1) <60)
			s[j]->improve_skill("literate",s[j]->query_int()/10+random(2));
		}
	}
	arg="";
	return;
}


void init()
{
   ::init();
	add_action("do_sit","sit");
	if (this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
    this_object()->set_heart_beat(1);
//	add_action("do_go","go");
//	add_action("do_recall","recall");
}


int do_sit()
{
	object me;
	me=this_player();

    if(me->query_temp("do_sit")) return notify_fail("你已坐下來專心聽講了。\n");
	if (me->is_fighting() ) return notify_fail("你正忙著打架，沒空聽課！\n");
	if(me->is_ghost()) return notify_fail("都死了，還讀什麼書..:P！\n");
	if(me->is_busy() ) return notify_fail("你正忙著，沒有空聽課。\n");

	message_vision("$N就地找了個位子坐下來聽課了。\n",me);
	me->set_temp("do_sit",1);
	return 1;
}
/*
void do_go(string arg)
{
	if (arg=="north" && this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
}

int do_recall(string arg)
{
    if (this_player()->query_temp("do_sit") ) 
        this_player()->delete_temp("do_sit");
	return 0;
}
*/
