inherit NPC;

void create()
{
        set_name("[0;1;37m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m", ({"radiated ant","radiated","ant"}) );
        set("long",@LONG
���e�O�@�����j�L�񪺥��ơA�A���T�h�èe�O���O�������g�u���ìV�C
LONG);
        set("unit","��");
        set("race", "beast");
        set("limbs", ({ "�Y��", "����", "Ĳ��","�E��"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 10);
        set("level",50);
        set_temp("apply/hit",30);      
        set_temp("apply/dodge",-20);    
        set("str",90);
        set("dex",80);
        set("chat_chance",20);
        set("chat_msg",({
           (: command("walk") :),
        }));
        setup();
}
void init()
{
      ::init();
        add_action("do_guard", "go");
        add_action("do_guard", "sneak");
}
int do_guard(string arg)
{

    object me;
    me=this_player();
    if(!this_player()->visible(this_object()) ) return 0;
    if(!userp(me)) return 0;
    if(!arg) return notify_fail("�A�n�h���̡H\n");
        write( name() + "�o�{�A���ʦV�A��A�צ�F�C\n");
        command("eh");
        return 1;
}
