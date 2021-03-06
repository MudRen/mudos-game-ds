inherit ROOM;
#include <ansi.h>
void create()
{
  set("light",1);
  set("long", HIC"\n君不見 黃河之水天上來　奔流到海不復回\n" 
              "君不見 高堂明鏡悲白髮  朝如青絲暮成雪\n" 
              NOR+CYN"       人生得意須盡歡  莫使金樽空對月\n"
              "       天生我材必有用  千金散盡還復來\n" 
              "       烹羊宰牛且為樂  會須一飲三百杯\n" 
              HIW+BLK"       岑夫子  丹丘生  將進酒  君莫停\n" 
              "       與君歌一曲      請君為我側耳聽\n" 
              "       鐘鼓饌玉不足貴  但願長醉不願醒\n" 
              "       古來聖賢皆寂寞  惟有飲者留其名\n" 
              HIR"       陳王昔時宴平樂  斗酒十千恣讙謔\n" 
              "       主人何為言少錢  徑須沽取對君酌\n" 
              "       五花馬  千金裘  呼兒將出換美酒\n" 
              "       與爾同消萬古愁\n"  
              "                     \n\t\t"NOR"       李白"HIW"《"HIY"將進酒"HIW"》\n"NOR);
    set("short",HIY"WorkRoom"NOR);
    set("exits",([
]));
    set("objects", ([ 
]));
        set("valid_startroom", 1);
  setup();
        call_other("/obj/board/whoami_b", "???");
}

void init()
{
     add_action("do_wizlist","wizlist");
     add_action("do_link","link");
     add_action("do_dellink","delink");  
     add_action("do_reboot","reboot");
}

int do_wizlist(string str)
{
    int i,n;
    object *user,room;
    user = users();
    n=sizeof(user);

message_vision(HIC"線上巫師一覽表\n"NOR,this_player());
message_vision(HIW"==============\n"NOR,this_player());
for(i=n-1;i>=0;i--)
{
 room = environment(user[i]);
 if(wizardp(user[i]))
       {
        message_vision(RANK_D->query_rank(user[i])+user[i]->name()+"("+user[i]->query("id")+")現在在"+room->query("short")+"裡\n",this_player());
       }
}
return 1;
}
 
int do_link(string arg)
{
    object me;
    me = this_player();

    if(!arg)
    return notify_fail("你要連結誰的房間。\n");
   if(file_size("/u/"+arg[0..0]+"/"+arg+"/workroom.c") <= 0)
    return notify_fail("沒有"+arg+"的工作室。\n");
   if(__DIR__"workroom.c"->query("exits/"+arg))
    return notify_fail("你已經有通往"+arg+"工作室的入口了。\n");
   __DIR__"workroom.c"->add("exits", ([arg :  "/u/"+arg[0..0]+"/"+arg + "/workroom.c"]));
    message_vision(HIC"$N增加了通往"+arg+"工作室的入口。\n"NOR,me);
    return 1;
}

int do_dellink(string arg)
{
    object me;
    me = this_player(); 

    if(!arg)
    return notify_fail("你要刪除對誰連結的房間。\n");
}
