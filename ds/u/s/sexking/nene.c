#include <ansi.h>
inherit NPC;
void create()
{
  set_name("妮妮",({"nene"}));
  set("long",HIC"一位美麗清純的少女\n"NOR
             HIM"長得真的有夠正點...\n"NOR);
  set("attitude", "peaceful");
  set("age",16);
  set("gender","女性");
  set("level",1);
  set("evil",-100);
  set("no_fight",1);
  set("no_more",1);
  set("chat_chance", 5);
  set("chat_msg", ({
 "妮妮微笑著說:sexking真可愛\n"
 "妮妮說:我很愛sexkingㄛ...\n"
}));
  set("inquiry",([
  "三圍" : "34,23,31..問這個幹嘛ㄚ?\n",
  "身高" : "158公分..問這個幹嘛ㄚ?\n",
  "sexking" : "他是我的男朋友ㄚ...你不要欺負他ㄛ..\n",
  "小麥草" : "他是我的男朋友ㄚ...你不要欺負他ㄛ..\n",
  "cominging" : "ㄣ..有聽過ㄛ..好像是疾風門的創始人ㄝ..\n",
  "tmr" : "ㄛㄛㄛㄛ...他訴八極門的創始人ㄇㄟ...\n",
  "acme" : "他好像是神武的創辦人...很多女生倒追他的樣子...\n",
  "linjack" : "聽說訴一個外貌很老內心卻很年青的人...ㄝ\n",
  "wilfred" : "一個很高速的硬碟...裡面有很多好用的LPC,sexking說他想把wilfred拆開來看ㄝ.\n",
  "luky" : "我不敢講....好像是一隻幻化成龍蝦的魔神ㄝ...\n",
  "shengsan" : "ㄊ是跟luky齊名的大魔神..ㄝ -_-\n",
]));
  setup();
}
void init()
{ 
add_action("hest","hest");; 
add_action("do_shout","shout");
add_action("do_kiss","kiss");
}
int hest(string str)
{ 
object me,ccc;
me=this_player();
if(!objectp(ccc=present("item",me) ) )
return notify_fail(HIR"警告.無持遙控器者不得控制它。\n"NOR);
command(str);
  return 1; 
}
int do_shout(string arg)
{
        object me;
        me=this_player();
        if(arg!="我愛妳")
        {
                notify_fail("你要叫啥麼ㄚ?\n");
                return 0;
        }
        if(this_player()->query("id") == "sexking")
        {
                message_vision(HIM"$N對妮妮大聲叫出：「我愛妳!」\n"NOR,me);
                command("blush sexking");
                command("kiss sexking");
                command("say 我也愛你。");
        }
        else
        {
                message_vision(HIW"$N大聲對妮妮叫出：「我愛妳!」\n",me);
                command(HIC"say 我又不認適你你幹嘛愛我?！。"NOR);
             }       
        return 1;
}
int do_kiss(string arg)
{
        object me;
        me=this_player();
        if(arg!="nene")
        {
                notify_fail("你要親誰?\n");
                return 0;
        }
        if(this_player()->query("id") == "sexking")
        {
                message_vision(HIM"$N輕輕的吻了一下妮妮的臉頰..好浪慢ㄛ\n"NOR,me);
                command("blush sexking");
                command("say 你真的很死相ㄟ。");
                 command("kiss sexking");
        }
        else
        {
                message_vision(HIW"$N正要親妮妮時被妮妮閃了開跌了一跤!\n",me);
                command(HIC"say 豬頭好險沒讓你親到！。"NOR);
             }       
        return 1;
}


