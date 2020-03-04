#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
  set_name("吳桂林", ({ "teacher wu","wu" }) );
  set("gender", "男性" );
  set("long",@LONG
一位熱心與樂天的老師。
LONG
);
  set("title","「"RED"熱血教師"NOR"」"NOR);
  set("age",55);
  set("level",100);
  set("exp",40);
  set("race","human");
  set("chat_chance_combat", 50 );        
  setup();
  
}

int accept_object(object who,object ob)
{
        object kaleidoscope;
        kaleidoscope=new(__DIR__"obj/kaleidoscope");

        if(ob->name()!="枯\樹枝")
        {
                command("say 你怎麼知道我剛好缺枯\樹枝呢!?");    
                return 0;
        }
        else {
                command("say 是不是老李這個貪錢鬼告訴你的!?"); 
                command("say 嗯......聽過你的解釋後..");
                command("say 雖然我很生氣,但是還是謝了你的枯\樹枝了!!"); 
                command("say 既然你那麼有心,我就把這個送你吧!!"); 
                kaleidoscope->move(who);
                destruct(ob);
                return 1;
        }

}

