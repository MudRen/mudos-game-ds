#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�۫ݭ�",({ "miss","�۫ݭ�" }));
        set("long","�@�Ӧʳf���q���p�j�C\n");
	set("level", 10);
	set("age",20);
	set("chat_chance", 8);
        set("gender","�k��");
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
    tell_object(me,this_object()->name()+"��A���G�w����{!!�кɱ����[!!\n");
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
        command("say �z�I���n���ڡI");
        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
        if(!ob) return;
        if( this_object()->query("helpready/"+ob->query("id")) )
                return;
        command("say "+ob->query("name")+"�A�A�O���]���C");
        ob->add_temp("quest/aovandis",1);       // �N�ۭt�������H���W�аO
        this_object()->set("helpready/"+ob->query("id"),1);     // �P id ����
}
