//Ĭ�l�_�Ĥ@��mob....�W�ɯ������L�v..
#include <ansi.h>
void goto_1();
void goto_2();
void goto_3();
inherit NPC;
inherit F_UNIQUE;
void create()
{
        set_name( "���L�v", ({ "fong-wu-yen","���L�v","fong",}));
        set("long", "�b�A���e���O�@�ӥ����¦窺�H�A���M�����@��H�~�A\n"
                    "���O��W�o�����D���F�@�]����F��C�L�Ⱖ��������\n"
                    "�w�Ⱥw�Ȫ���....�y�W�����D�����ݵۧA�A�����D����A\n"
                    "���ۤ���D�N....�A���T�y�U��j���@�w���C\n");
  
        set("title",CYN "����ŪŨ�"NOR);
        set("gender", "�k��");
        set("age", 27);
        set("level", 47);
        set("dex", 97);
      set("adv_class",2);    
      set("class1","�K�P��"); 
     set("class2","�_��");
      create_family( MAG "�_��" NOR ,2,"��");

   set("guild_gifts",({-2,-2,7,17}));
   
        set("chat_chance",3);
        set("chat_msg",({(:command, "grin":),
                                  (:command, "sing":),
                                  (:command, "snicker":),
                           (: random_move :),
  }));

        set_skill("stealing", 100);
        set_skill("sneak", 100);        
        set_skill("backstab", 100);
        set_skill("peep", 100);
        set_skill("hide", 100);
         set_skill("perception", 100);
        set("env/wimpy", 80);
        
        set("inquiry/name", "�ڥs�����L�v�A�S�٧���ŪŨ�C
        ");

        set("talk_reply","�A�b�o�����ڧ⭷�a�I�ڶi�h�ݬݦ�ԣ�ȿ������N��C :P");

/*set("schedule",
([
        "21" : (: goto_1 :),
        "01" : (: goto_2 :),
        "03" : (: goto_3 :),
        "07" : (: del:),
]));
*/

        setup();
        add_money("coin", 10000);
        carry_object(__DIR__"wp/cloud_dagger.c")->wield();
        carry_object(__DIR__"eq/sky-walk_b.c")->wear();
        carry_object(__DIR__"eq/stars_c.c")->wear();
}



int accept_object(object who, object ob)
{
object wp;
        wp=this_object()->query_temp("weapon");        
        if(ob->name()!="�j�Ѫ����J")
                return 0;
        else {

        if(wp->name()!="�d���P")
        {
        command("say �u�O�h�¤F...�i�O�ڨS����n�F��i�H�����A�C\n");
        command("say �o�˦n�F�A�A���o�F��h�@���s��P�ȴ̪��a��C\n");
        command("think");
        command("say �N�������̪�����Q�A�o���ӷ|���A�n�B���C\n");
        say("���L�v�n���ٷQ���Ǥ���A���O�n�F�n�Y�N���F�C\n");
        command("idle");
        }
          else {

           say("���L�v�ݨ�o�ӥ��J�y�ɤj�߭Y�g�I�I\n");
           command("say �Ӧn�F�I���§A���ڧ�쥻�����_�I\n");
           command("unwield dagger"); 
           command("grin");
           command("say �o�å�F��O�ڱq�j�����X�Ӫ��A�٤����ΡC\n");
           command("say ���F�����A�������A�o�å�N�e���A�a�I\n");
           command("give dagger to " + this_player()->query("id") );
           command("say ��|�����I�ڥh�]�I"); 
           destruct(ob);
           destruct(this_object());
           return 1;
        }
         return 1;
        }
         } 
void relay_emote(object ob, string verb)
 {
 	 if( !userp(ob) )
 	  return 0;

	switch(verb) {
	case "?":
			command("say �Aı�o�ګܩ_�ǶܡH");
                        command("hehe");
                        command("say �A�b�o�̫ݤ[�F�ܧִN�ܱo�ܧڤ@�� :P");
                        command("cac");
                        say(CYN"���L�v��M�����F�A�u�ѤU�L���g���٦b�A����r�ޡC/n"NOR);
                        destruct(this_object());
			break;
	case "pig":
			command("say �Aı�o�ګܲ¶ܡH");
                        command("hehe");
                        command("say �A�b�o�̫ݤ[�F�ܧִN�ܱo�ܧڤ@�� :P");
                        command("cac");
                        say(CYN"���L�v��M�����F�A�u�ѤU�L���g���٦b�A����r�ޡC\n"NOR);
                        destruct(this_object());
			break;
        case "crazy":
			command("say �Aı�o�ںƤF�ܡH");
                        command("hehe");
                        command("say �A�b�o�̫ݤ[�F�ܧִN�ܱo�ܧڤ@�� :P");
                        command("cac");
                        say(CYN"���L�v��M�����F�A�u�ѤU�L���g���٦b�A����r�ޡC\n"NOR);
                        destruct(this_object());
			break;
        case "starcraft":
                        
                        command("say ���n�I�A�S�����L�ڡA�@�I�N��]�S���C");
                        command("snort");
                        break;
        case "accuse1":
                        
                        command("say ���S�p��A�ܤ֧ڳo���ڽ��S���|�Q����q�C");
                        command("grin");
                        break;
	default:
			command(verb + " " + ob->query("id"));
                        break;
	}
}
void goto_1()
{
        if(!find_object("/open/world1/cominging/area/bnorth3")) return;
 this_object()->move("/open/world1/cominging/area/bnorth3");
 message_vision(HIG"�Ať��@�}���B�B���n���A�u��$N"HIG"�q�𪺥t�@�Y½�F�X�ӡC\n"NOR, this_object());
}

void goto_2()
{
        if(!find_object("/open/world1/acme/area/wynd")) return;
 this_object()->move("/open/world1/acme/area/wynd");
 message_vision(HIG"�Ať��@�}���B�B���n���A�u��$N"HIG"�q�𪺥t�@�Y½�F�X�ӡC\n"NOR, this_object());
}

void goto_3()
{
        if(!find_object("/open/world1/tmr/area/wynd")) return;
 this_object()->move("/open/world1/tmr/area/wynd");
 message_vision(HIG"�Ať��@�}���B�B���n���A�u��$N"HIG"�q�𪺥t�@�Y½�F�X�ӡC\n"NOR, this_object());
}
void del()
{
          command("say ��A�t���h�Ӧ��u�F :P");  
          say (HIB"���L�v�����@�D�A���}�F�A�����u�C\n"NOR); 
          destruct(this_object());
        return;
}
void attack()    
{
        int hp,max_hp ;
        hp=this_object()->query("hp");
        max_hp=this_object()->query("max_hp");
        if(hp==max_hp) return 0;

          command("say ���������A��I��I�C�X�v���Q�A�k���ԤԡI�I");  
          say (HIB"�u�����L�v�§A�ĨӡA�A�ٷd���M�����^�ơA�L�����v�w�����b�·t�������F�C\n"NOR); 
          destruct(this_object());
          return ;
}
