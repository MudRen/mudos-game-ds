#include <npc.h>
inherit F_BANDIT;

void create()
{
          set_name("���", ({ "walk corpse" , "corpse" ,"walk"}) );
        set("long",@long
�o�O�@��w�g�G�ꨣ��������A���o�٬O��w�B�樫�C
long
);
        set_race("human");
        set("age", 500 );
        set_stat_maximum("gin", 200);
        set_stat_maximum("hp", 200);
        set_attr("str",20);
        set_attr("cps",20);
		set_skill("sword",30);
        set_skill("parry",40);
        set_skill("dodge",40);
        set("title","���`����");
        setup();
        set_level(5);
        do_heal();
        switch(random(4) ) {
        	case 0: // �S���
		        carry_object(__DIR__"obj/shortaxe")->wield();
			    break;
        	case 1: // �S��j
		        carry_object(__DIR__"obj/shortpike")->wield();
			    break;
        	case 2: // �S��M
		        carry_object(__DIR__"obj/shortknife")->wield();
			    break;
        	default: //  �S��C
		        carry_object(__DIR__"obj/shortsword")->wield(); 
        }
}


