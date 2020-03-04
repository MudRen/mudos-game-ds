#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIC"�Ӣߵo��M��"NOR, ({"eq man","man"}) );
        set("long", "�M�����C���Ū����a�ҳ]�p���u�@�H���A�i�H�V�������Ӣ�(want)�C\n");
        set("unit","��");
        set("race", "human");
        set("age", 2);
        set("level",1); 
        set("no_kill",1);
        set("dex",1);
        set("str",1);
        set("con",1);
        set("chat_chance",3);
        set("chat_msg",({
                ("�Ӣߵo��M�����G�o��C���ŢӢߡ�\n"),
        }));

        setup();

}
void init()
{
     add_action("do_want","want");
}
int do_want(string arg)
{
    object ob,me;
    ob=this_object();
    me=this_player();  
    if(me->query_temp("wanted")==1)   
    {
    command("say "+(string)me->query("name")+"�A�w�g�n�L�F��I\n");    
    return 1;
    }
    if(me->query("level")> 5)    
    {
    command("say "+(string)me->query("name")+"�A�A�����Ťw�W�L Lv.5�A�W�L�F����A�����o�e�C\n");  
    return 1; 
    }
    else{

    command("say "+(string)me->query("name")+"�n�n�[�o��I");  
    command("addoil");
    command("say "+(string)me->query("name")+"�A�ڵ��A�Ǹ˳Ƨa�I");   
    switch(random(5))
    {
    case 0:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me);
    new(__DIR__"obj/ds-surcoat.c")->move(me);
    new(__DIR__"obj/ds-wrists.c")->move(me);
    new(__DIR__"obj/ds-pants.c")->move(me);  
    me->set_temp("wanted",1);
    break;
    case 1:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me);
    new(__DIR__"obj/ds-surcoat.c")->move(me);
    new(__DIR__"obj/ds-wrists.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    case 2:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me);
    new(__DIR__"obj/ds-surcoat.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    case 3:
    new(__DIR__"obj/ds-armor.c")->move(me);
    new(__DIR__"obj/ds-shield.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    case 4:
    new(__DIR__"obj/ds-armor.c")->move(me); 
    me->set_temp("wanted",1);
    break;
    }
    }
    return 1; 
}

