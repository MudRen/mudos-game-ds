#include <ansi.h>
inherit NPC;
void create()
{
    set_name("招待員",({ "miss","招待員" }));
        set("long","一個百貨公司的小姐。\n");
	set("level", 10);
	set("age",20);
	set("chat_chance", 8);
        set("gender","女性");
    set_skill("unarmed",10);
	set_skill("dodge",25);
	set_skill("combat",5);
	setup();
        add_money("dollar",150);
}

void init()
{
	call_out("delay",2,this_player());
}
void delay(object me)
{
    tell_object(me,this_object()->name()+"對你說：歡迎光臨!!請盡情參觀!!\n");
	return;
}

void a(object tob)
{
	delete_temp("uselo");
	return;
}

void make_mark()
{
        object *enemy, ob;
        command("say 哇！不要打我！");
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if(!ob) return;
        if( this_object()->query("helpready/"+ob->query("id")) )
                return;
        command("say "+ob->query("name")+"，你是個魔鬼。");
        ob->add_temp("quest/aovandis",1);       // 將欺負市民的人做上標記
        this_object()->set("helpready/"+ob->query("id"),1);     // 與 id 結仇
}
