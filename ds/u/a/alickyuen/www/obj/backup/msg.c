#include <ansi2.h>
inherit ITEM;
mapping color = ([
// ---- 背景色 -----
"$HBWHT$" : HBWHT,
"$BBLK$"  : NOR+BBLK,
"$HBRED$" : HBRED,
"$BRED$"  : NOR+BRED,
"$HBGRN$" : HBGRN,
"$BGRN$"  : NOR+BGRN,
"$HBYEL$" : HBYEL,
"$BYEL$"  : NOR+BYEL,
"$HBBLU$" : HBBLU,
"$BBLU$"  : NOR+BBLU,
"$HBMAG$" : HBMAG,
"$BMAG$"  : NOR+BMAG,
"$HBCYN$" : HBCYN,
"$BCYN$"  : NOR+BCYN,
"$BLINK$" : BLINK,

// ---- 前景色 -----
"$BLK$" : HIW+BLK,
"$WHT$" : NOR+WHT,
"$HIW$" : HIW,
"$RED$" : RED,
"$HIR$" : HIR,
"$GRN$" : GRN,
"$HIG$" : HIG,
"$YEL$" : YEL,
"$HIY$" : HIY,
"$BLU$" : BLU,
"$HIB$" : HIB,
"$MAG$" : MAG,
"$HIM$" : HIM,
"$CYN$" : CYN,
"$HIC$" : HIC,
"$NOR$" : NOR
]);
void create()
{    
   set_name(HIY"宣"+HIW"傳"+HIR"喇"+HIM"叭"NOR,({ "megaphone","msg" }));
   if( clonep() )
         set_default_object(__FILE__);
   set_weight(1);
   set("no_drop",1);
   set("can_give",1);
   set("no_sell",1);
   set("unit", "台");
   setup();
}
int query_autoload() { return 1;}

void init()
{
    if(this_player()->query("id") == "fedex" || this_player()->query("env/wizard_open"))
    {
      add_action("do_message","msg");
      add_action("do_shot","shot");
      add_action("do_get","gett");
      add_action("do_color","color");
      this_player()->set_temp("invis",(int)SECURITY_D->get_wiz_level(this_player()));
      this_player()->set_temp("define_look",NOR" 正站在這裡 "HIG"<斷線中>"NOR);
      this_object()->set("long",
      "�歈������������������������������綅n"
      "��"HIY"shot"NOR"  (立即死亡)              �鱋n"
      "��"HIY"gett"NOR"  (拿取容器內的某樣物品)  �鱋n"
      "��"HIY"msg"NOR"   (將頻道的文字加上色碼)  �鱋n"
      "��"HIY"color"NOR" (色碼列表)              �鱋n"
      "�裺������������������������������嫹n");
    }
    else { set("long",HIR"喇叭牌按摩棒"HIW+BLK"[飢渴型專用]"NOR); }
}

int do_message(string arg)
{
    int i;
    object me = this_player();
    string msg,channels;
    string *source_color;
    string *target_color;

    if( !arg || sscanf(arg, "%s %s",channels,msg) != 2 )
      { return notify_fail(HIW+BLK"[格式]: "HIR"msg <頻道> <內容>\n"HIW+BLK"[頻道]: ["HIR"say、emote、past"HIW+BLK"]\n"NOR); }

    source_color = keys(color);
    target_color = values(color);
    for( i=0;i<sizeof(source_color);i++ )
       msg = replace_string(msg, source_color[i], target_color[i]);

    if( channels == "say" || channels == "'")
    {
       message_vision(YEL"$N說﹕"+msg+NOR"\n",me);
       return 1;
    }
    else if( channels == "emote")
    {
       message_vision(YEL+msg+NOR"\n",me);
       return 1;
    }
    else if( channels == "past" )
    {
       message("world:world1:vision","\n\t"+msg+NOR"\n\n",users());
       return 1;
    }
    else
    { return notify_fail(HIW+BLK"請使用頻道: ["HIR"say、emote、past"HIW+BLK"]\n"NOR); }
 return 1;
}

int do_shot(string arg)
{
    int val=0;
    object *list,who,ob,me;
    me = this_player();
    ob = this_object();
    list = all_inventory(environment(me));
    if(!arg)
       return notify_fail(HIW+BLK"[格式]: "HIR"shot <某人> || <all>\n"NOR); 
    if(arg == "all")
    {
       foreach(object user in list)
         { if(living(user) && user != me) val++; }
       if(val<1)
         return notify_fail("這裡只有你一個人...\n");
       foreach(object user in list)
       {
          if(!living(user) || userp(user)) continue;
          tell_room(environment(me),HIC+user->name()+"突然覺的好冷。\n"NOR);
          user->set_temp("temp/death_type",HIR"[被"+me->name(1)+"玩死]"NOR); 
          user->die();
       }
       return 1;
    }    
    if(!(who = present(arg, environment(me))) || !who->is_character() || who->is_corpse() )
       return notify_fail("這裡沒有這個人。\n");
    if(arg == "fedex")
       return notify_fail("你無法對"+who->name(1)+"下這個指令。\n");
    tell_room(environment(who),HIC+(string)who->query("name")+"承受不住心中的悲痛自殺了。\n"NOR);
    tell_object(who,HIW+BLK"[你自殺了]。"NOR);
    who->delete("env/immortal");
    who->set_temp("temp/death_type",HIR"[自殺身亡]"NOR); 
    who->die();  
    return 1;
}

int do_get(string arg)
{
    int i;
    object me,item,who;
    string obj,user;
    me = this_player();

    if(!arg || sscanf(arg, "%s from %s",obj,user) != 2)
       return notify_fail(HIW+BLK"[格式]:"HIR" gett <某物> from <某人>\n"NOR);
    if(!(who = present(user, environment(me))) )
       return notify_fail("你找不到 "+user+" 這樣東西。\n");
    if(who->query("id") == "fedex")
       return notify_fail(who->name(1)+"回頭瞪了你一眼。\n");
    if(obj == "all")
    {
        if(sizeof(all_inventory(who))<1)
           return notify_fail(who->name()+"身上沒有任何東西。\n");
        foreach(object ob in all_inventory(who))
        {
       message_vision("$N從$n身上搜出一"+item->query("unit")+item->name(1)+"。\n",me,who);
           ob->move(me);           
        }
        return 1;
    }
    if(!item = (present(obj,who)))
       return notify_fail(who->query("name")+"身上並沒有"+obj+"這件東西\n");
    message_vision("$N從$n身上搜出一"+item->query("unit")+item->name(1)+"。\n",me,who);
    item->move(me);
    return 1;
}

int do_color()
{
    write("
◎色碼對照表
�歈���������������������������������
�曮e景色                          ��
��$RED$ - "RED"深紅色"NOR"    $HIR$ - "HIR"亮紅色"NOR"��
��$GRN$ - "GRN"深綠色"NOR"    $HIG$ - "HIG"亮綠色"NOR"��
��$YEL$ - "YEL"土黃色"NOR"    $HIY$ - "HIY"亮黃色"NOR"��
��$BLU$ - "BLU"深藍色"NOR"    $HIB$ - "HIB"亮藍色"NOR"��
��$MAG$ - "MAG"暗紫色"NOR"    $HIM$ - "HIM"粉紅色"NOR"��
��$CYN$ - "CYN"藍綠色"NOR"    $HIC$ - "HIC"天青色"NOR"��
��$BLK$ - "HIW+BLK"淺灰色"NOR"    $HIW$ - "HIW"亮白色"NOR"��
��                                ��
�灟I景色                          ��
��$HBRED$ - "HBRED"深紅色"NOR"                ��
��$HBGRN$ - "HBGRN"深綠色"NOR"                ��
��$HBYEL$ - "HBYEL"土黃色"NOR"                ��
��$HBBLU$ - "HBBLU"深藍色"NOR"                ��
��$HBMAG$ - "HBMAG"暗紫色"NOR"                ��
��$HBCYN$ - "HBCYN"藍綠色"NOR"                ��
��$BLINK$ - "BLINK"閃爍"NOR"                  ��
�裺��������������������������������嫹n");
return 1;
}
