#include <npc.h>

inherit F_VILLAGER;

void create()
{
        set_name("王風", ({ "wang feng","feng" }) );
        set_race("human");
        set("age", 40);
        set("long", "王風是從小就住這裡的獵戶，以打獵野獸為生，技巧倒也頗為高明。\n");
        set("chat_chance", 5);
        set("chat_msg", ({
                "王風望著海面說道：這陣子海風倒也平靜，或許可以準備一下，再上野蠻島上打獵了。\n",
                (: command("sing") :),
        }));

        setup();
}

int accept_fight(object ob)
{
        
        return 0;
}

/* Quest:提示 猜拳 拳法 */
void relay_say(object ob, string arg)
{
        if( arg=="te-o tsunai dara itemiyo"  )  {
              command("say 哦...這句話的意思是：『大首領愛吃鴨肉的毛病又起了，偏偏這島上又沒有鴨子。』");
              return ;
        }
        if( arg=="mo eruyo natsukino kagayaku okani"  )  {
              command("say 這句我就不清楚了，好像是首歌詞吧。");
              command("think");
              return ;
        }
        if( arg=="語言"  )  {
              command("say 哦...您要是有聽不懂的野蠻話，不彷可以來問問我。");
              command("ssmile");
              return ;
        }
        if( strsrch(arg,"野蠻")!=-1 
         || strsrch(arg,"打獵")!=-1 ) {
              command("say 哦...我從小就常去附近的野蠻島上打獵，倒也熟幾句他們的語言。");
              return ;
        }
}

