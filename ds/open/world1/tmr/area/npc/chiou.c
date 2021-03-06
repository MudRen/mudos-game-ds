#include <ansi.h>

inherit NPC;

void create()
{
        set_name("秋先", ({ "chiou-shian","chiou","shian" }) );
        set("nickname", "灌園叟");
        set("gender", "男性" );
	set("long",
"一個年逾七十的老叟，生平酷好栽花種果，若偶覓得種異花，就是拾\n"
"著珍寶，也沒有那般歡喜。聽說他乃「傲梅山莊」副莊主的父親，只\n"
"是為了種花，其他事都棄撇了。\n"
 	);	
        set("score", 15000);
        set("con", 19);
        set("str", 21);
        set("int", 20);
        set("age",63);
        set("level",15);
        set_skill("parry", 60);
        set_skill("unarmed", 60);

        set("chat_chance", 2);
        set("chat_msg", ({
		"秋先高聲吟道：朝天湖畔水連天，不唱漁歌即採蓮........\n"
		"秋先高聲吟道：小小茅屋花萬種，主人日日對花眠.......\n\n"
		"秋先高聲唱道：朝灌園兮暮灌園，灌成園上百花鮮...........\n"
		"秋先高聲唱道：花開每恨看不足，為愛看園不肯眠...........\n\n"
        }));

        set("inquiry", ([
         "花": "呵呵呵..老夫生平最愛就是種花、賞花、葬花、浴花，最恨人家攀枝折朵！\n",
        ]) );

        set("chat_chance_combat", 50 );        
	set("chat_msg_combat", ({
                "秋先叫道﹕殺人哪﹗殺人哪﹗\n",
                (: command, "surrender" :),
         }) );
  
	setup();
          carry_object(__DIR__"wp/wolf-fist");
            carry_object(__DIR__"obj/wine");
          add_money("silver",3);
}

int accept_object(object who, object ob)
{
	object wine;
        if( ob->query("name") != "夜落金錢" )	return 0;
	command("wa");		
	command("say 竟有這種老夫沒有看過的奇花！！！");
	command("tsk");		
	command("say 真是讓老夫大開眼界，這袋百花釀就送你以聊表謝意了。");
	wine=new(__DIR__"obj/wine");
	wine->move(who);
	destruct(ob);
	return 1;		
}
