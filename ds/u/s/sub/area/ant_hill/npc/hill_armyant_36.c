inherit NPC;

void create()
{
        set_name("�L��", ({"army ant","army","ant"}) );
        set("long",@LONG
�j�����E���A�Ӥj�����ߡA���e�O�@�����j���L�ơC
LONG);
        set("unit","��");
        set("race", "beast");
        set("limbs", ({ "�Y��", "����", "Ĳ��"})); 
        set("verbs", ({ "bite","claw","crash" })); 
        set("age", 1);
        set("level",36);
        set_temp("apply/hit",10);      
        set_temp("apply/dodge",-30);    
        set("str",62);
        set("dex",45);
        set("chat_chance",5);
        set("chat_msg",({
                "�L�Ƥ����a�����e���E���C\n",
    (: random_move :),
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
    if(!userp(me)) return 0;
    if(!this_player()->visible(this_object()) ) return 0;
    if(!arg) return notify_fail("�A�n�h���̡H\n");
        write( name() + "�o�{�A���ʦV�A��A�צ�F�C\n");
        command("eh");
        return 1;
}
