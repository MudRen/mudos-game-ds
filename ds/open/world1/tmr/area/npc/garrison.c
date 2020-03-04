inherit NPC;
void create(){
	set_name("�u���x�L", ({ "garrison" }) );
	set("class","soldier");
	set("age",25);
	set("level",20);
            set_skill("sword", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 50);
            set_skill("dodge", 50);

	set("long",
            "�@�Ӧu�@�������x�L�A�ݰ_�Ӻ믫�����A�M�`�a�ݵ۹L�����H�s�A����\n"               	"�������Y�������C\n"  );
	setup();

            carry_object(__DIR__"wp/sword.c")->wield();
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
        case 0: command("say ���D�R�j�x�N���T�������M�x���T\n"); break;
        case 1: command("say �ܹD�R�ϤF�ϤF�T�S�̡̭M���U�o�ӭ�{�T\n"); break;
        case 2: command("say �ޡT�A�Q�F����S"); break;
        case 3: command("say �ӤH���T���U���ӥi�ê��å�T"); break;
        }
        kill_ob(me);
        me->fight_ob(this_object());
}

