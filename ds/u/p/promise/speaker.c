// 神話世界﹒西游記﹒版本４．５０
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>
string *msgs=({
HIW"現在七域全面改革，有建議或些提議者，全Post在朝天樓的板！！"NOR,
HIW"因Help檔有些許\老舊，所以徵幾位老玩家來幫忙更新，有意者上線洽Promise！！"NOR,
HIW"玩Mud之餘，也要注意身體與健康，Ds巫師關心各位玩家！！"NOR,
HIW"請新手多多利用Newbie練功\區，以便快速成長！！"NOR,
HIW"有發生任何Bug，請迅速Report Bug，讓巫師能夠第一時間的去除蟲子！！"NOR,
HIW"慶祝中華隊逆轉勝韓國泡菜隊，Recall特別販賣韓國泡菜與日本壽司，以玆慶祝！！"NOR});
void create()
{
        set_name(HIY"七域大聲公"NOR, ({"ds speaker"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", HIC"大聲派掌門人"NOR);
        set("nickname", HIG"他媽的吵死人了的人"NOR);
       set("long", "代表Promise發言一切他想說的!!\n");
       set("no_kill",1);
       set("no_fight",1);
       setup(); 
      remove_call_out("msg");
       call_out("msg",600);
      }
void msg()
{
string msgs=msgs[random(sizeof(msgs))];

     message("world:world1:vision",HIW"\n【"HIM"七域快報"HIW"】："+ msgs +"\n\n"NOR,users());
      
      }


