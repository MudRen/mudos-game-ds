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
set_skill("parry", 100);
set_skill("dodge", 100);
set_skill("sword", 100);
       
	setup();
carry_object( "/u/s/shengsan/npc/wp/lukysword.c")->wield();
}
//void init()     <----�Ƨѿ�
//{
 //       object ob;
  //      if( objectp( ob = find_living("bennyng") ) )
 //       {
//ob-> die();
 //       }
 //       ::init();
//}
//'void init()
//{
//        object leader;
//        if( objectp( leader = find_living("alickyuen") ) )
//        {
//                set("creater",leader);
//                set_leader(leader);
//                return;
//        }
//        ::init();
//}


