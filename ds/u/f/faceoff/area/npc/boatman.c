#include <ansi.h>
inherit NPC;
void create()
{
 set_name("船老大",({"boat man","man"}));
 set("long","他是無砂港通往扶桑一帶的船夫。\n");
 set("age",41);
 set("gender","男性");
 set("level",10);
 set("chat_chance",20);
 set("chat_msg", ({"船老大氣呼呼的說: 船沒開是老子的錯? 有種的就跟老子幹上一架!.\n",
	           "船老大氣呼呼的說: 去問海政司的龜兒子們啦! 他媽的, 一張簽出條也發不下來.\n",
                            (:command("pig"):),
 }));
	set("chat_chance_combat",200);

	set("talk_reply","怎麼樣? 又來一個怪老子的? 他媽的"+HIG+"謝基"+NOR+"......!\n"NOR);

	set("inquiry/謝基","就是那個兔崽子! 誰敢當面跟他說"+HIG+"韃靼舟"+NOR+", "+CYN+"保證龜兒子連屁也放不出一個!\n"NOR);

	set("inquiry/韃靼舟","就是這艘船的舟號啦! 要不是海政司那批吃白飯的, 怎會連一張"+HIG+"簽出條"+NOR+"也發不出來?.\n"NOR);

	set("inquiry/簽出條","那也是海政司那批人發出來的鬼東西! 偏偏又不發給咱們, 根本是純心找喳....\n");


 set("chat_msg_combat",({                         
                         (:command,"hmm":),
 }));
 setup();
}

int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="簽出條")
        {
           command("? "+who->query("id"));
           return 0;
        }
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" 請你等一下。");
             return 0;
          }
	message_vision("$N給了船老大一張"+ob->query("name")+"。\n",who);
             obj->start_busy(7);
             obj->set_temp("get_paper",1);
             destruct(ob);
             call_out("get_paper",1,obj);
             return 1;
        }

}

void get_paper()
{
      int i;
      object me,obj,p;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("get_paper");
      switch( i ) {
          case 1:
            command("wa");
            command("say 他奶奶的...這是簽出條啊!!");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 2:
            message_vision(YEL"船老大望了$N一眼...。\n"NOR,me);
         message_vision(YEL"船老大忽然走進船艙...。\n"NOR,me);
         command("hoho");
            obj->set_temp("get_paper",i+1);
            call_out("get_paper",1,me);
            break;
          case 3:
       tell_object(me,"船老大對你說道: 這是我從南海帶來的寶駒, 這就送給你吧...\n");
	p=new(__DIR__"obj/blood_horse");
        	p->move("/u/f/faceoff/area/seacoun42");
              obj->delete_temp("get_paper");
            break;
            }
}


