inherit NPC;
void create(){
	set_name("ĵ��", ({ "police" }) );
	set("class","soldier");
	set("age",25);
	set("level",15);
            set_skill("gun", 30);
	set_skill("parry", 45);
	set_skill("unarmed", 30);
            set_skill("dodge", 36);
	set("chat_chance_combat", 50);
            set("chat_msg_combat", ({
	(:command("shoot"):),
	(:command("reload clip"):),
	            }) );
	
	set("long",
            "�@�ӭt�d���޷s���o����ĵ��A�L�����e�`�a�˵��C�@�ӤH�A����\n"               	"�������Y�������C\n"  );
	setup();

            carry_object(__DIR__"wp/lasergun")->wield();
	carry_object(__DIR__"wp/laserclip");
            carry_object(__DIR__"eq/armor")->wear();
           carry_object(__DIR__"eq/boots.c")->wear();
}

int accept_fight(object ob)
{
        switch(random(3)) {
                case 0: command("shake" );      break;
                case 1: command("say ���}���}�T\n");            break;
                case 2: command("hehe" );       break;
        }
        return 0;
}

void init()
{
	::init();
         add_action("do_kill","kill");
}

int do_kill(string arg)
{
        object *ob,me;
        int i;

        me=this_player();

        if (!arg) return 0;
        if(!objectp(present(arg, environment(me)))) return 0;
        
        if( is_fighting(me) ) return 0;
        command("say ���D�R�x�H�y�ϰաH�����ñ��H�I�I�h���a ...\n");

        ob=all_inventory(environment());
	for(i=0;i<sizeof(ob);i++)
	{
		ob[i]->soldier_assist(this_object(), me);
	}
	return 1;
}

void soldier_assist(object alert, object me)
{
          if(
             !living(this_object())
        ||      is_fighting(me) )
                return;

          switch(random(4)) {
        case 0: command("say ���D�Rĵ��T�O�k�F�I\n"); break;
        case 1: command("say �ܹD�R�S�̡̭M���U�o�ӭ�{�T\n"); break;
        case 2: command("say �ޡT�A�Q�F����S"); break;
        case 3: command("say �O�ϧܤF�T�ۭ��a�I"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

