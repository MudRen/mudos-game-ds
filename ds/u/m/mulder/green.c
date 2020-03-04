#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","綠島");
        set("long",@LONG
這裡是 ＤＳ的「離島」管訓所，如果你被送到這裡，表示你違反
了遊戲規則， 請好好的反省一下你的所作所為，想離開的話只要確定
你不再犯任何規條，就可以告訴巫師，請他把你送出。
LONG
        );
        set("hide_exits",([
  "out" : "/d/wiz/hall1.c",
]));
        setup();
}

void init()
{
        if ( !wizardp(this_player()))
        {
                add_action("break_cmd","",1);
                call_out("green", 2, this_player());
        }
        else 
        {
                add_action("do_summon","sum");
        }
}

int break_cmd()
{
        if((string)query_verb() == "look") return 0;    
        if((string)query_verb() == "say") return 0;    
        if((string)query_verb() == "help") return 0;
      if((string)query_verb() == "recall") return 0;
        tell_object(this_player(),"你在管訓中 ，只能下look,help 二個指令 。\n");
        return 1;
}

void green()
{
        tell_room(environment(this_player()),
                "你聽到耳邊傳來綠島小夜曲的歌聲: \n\n"+
        GRN     "這綠島像一隻船  在月夜裡搖啊搖\n"+
                "姑娘呀妳也在我的心海裡飄啊飄\n"+
                "讓我的歌聲隨那微風  吹開了妳的窗簾\n"+
                "讓我的衷情隨那流水  不斷地向妳傾訴\n"+
                "椰子樹的長影掩不住我的情意\n"+
                "明媚的月光更照亮了我的心\n"+
                "這綠島的夜已經這樣沉靜\n"+
                "姑娘呦∼妳為什麼還是默默無語\n\n"NOR
        );
        return;
}

int do_summon(string str)
{
        object me=this_player(),ob;
        if ( !str ) return notify_fail("<Syntax>: Summon <player id>\n");
        if( this_player()->query("id")!="mulder")return 0;        
        ob = LOGIN_D->find_body(str);
//      tell_room(environment(ob),"天空中伸出一隻大手用戒令中的關禁條法"+(string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
//      tell_object(ob,"一隻手把你抓了起來, 你眼前一陣黑....\n");
        ob->move(environment(me));
        ob->set("startroom", "/u/c/cominging/green.c");
        tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
//      tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+"把你弄過來的.\n");
//      tell_room(environment(ob),(string)ob->query("name")+"突然出現"+"在你眼前\n",({me,ob}));
        return 1;
}

