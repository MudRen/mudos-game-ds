// Npc: /u/a/alickyuen/npc/1.c

inherit NPC;

void create()
{
	set_name("�s���k�l", ({"noriko"}) );
	set("long", "�o�O�@�ɤW�̬��R���k�q��.\n");
	set("race", "�H��");
	set("age", 24);
	set("level", 60);
  set("gender", "�k��" );
set("max_hp",70000);
set("max_mp",70000);
set("max_ap",70000);
set_skill("hungchen-sword",100);
set_skill("parry", 100);
set_skill("dodge", 100);
set_skill("sword", 100);
set("con",170);
set("str",170);
set("dex",170);
set("int",170);
set("title","���ӲĤ@�N�s�P��O������");
                set("chat_chance_combat", 20);
                set("chat_msg_combat", ({
(:command("exert hungchen-sword"):),
}));
	setup();
carry_object( "/u/s/shengsan/npc/wp/soulsword.c")->wield();
}
void init()
{
        object leader;
       if( objectp( leader = find_living("alickyuen") ) )
        {
                set("creater",leader);
                set_leader(leader);
                return;
        }
      ::init();
}


