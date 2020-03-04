#include <ansi.h>  
//#define RS_EN "/open/world1/tmr/area/square.c"
inherit ITEM;
void create()
{
     set_name("祭壇石",({"altar slab","slab"})); 
     set("long","一塊大石頭，上面刻有一隻狐狸的畫像，上面沾滿了灰塵，似乎很久沒放過東西了。\n"
                "旁邊則撰有 [ 如要祭拜(altarage)，請放祭品，但勿放狐狸的屍體，切記！]\n");
     set("no_sac",1); 
     set("no_get",1);
     set_weight(99999999);   
     setup();
}  
void init()
{
        add_action("do_altarage","altarage");
} 

int do_altarage(string arg)
{  
    object me=this_player(),z;
        if(!me) return 0;   
        if(this_object()->query_temp("altaraged")==1) return notify_fail("不久前才有人祭拜過。\n");
        if(!arg || arg!="小狐狸的屍體 on slab") return notify_fail("你要用什麼祭拜?\n");
        if(!objectp(z=present("corpse",me) ) )
                return notify_fail("你沒有東西可以祭拜啊 ? \n");
        message_vision("\n$N將小狐狸的屍體放在祭壇石上。\n",me);   
        this_object()->set_temp("altaraged",1); 
  {
    destruct(z); 
    message_vision("\n小狐狸的屍體突然往祭壇石內沉了下去•••不見了！\n",me);
    call_out("GO_FOX_ONE",10);
  } 
    return 1;
}   

void GO_FOX_ONE()
{
     message("world:world1:vision",HIR"\n\n\t.........嘿.........嘿嘿嘿嘿................\n\n"NOR,users()); 
     call_out("GO_FOX_TWO",5);
     return;
} 
void GO_FOX_TWO()
{
     object me=this_player(),foxp,npc,room;
     room=load_object(environment(this_object())->query("exits/southdown"));
   if( room && objectp(npc = present("miao-jian bonze",room)))
    {  
   message("world:world1:vision",HIW"\n\t一隻巨大的野獸，狂囂似的站在凌雲頂峰，妙見和尚見此狀•••\n\n"
                    +HIC"\t飛奔似的•••"+HIR"速前應戰！\n\n"
                    +MAG"\t大量妖氣不斷竄升••"+HIM"九尾"+HIW"妖狐"+NOR"睥睨一切！\n\n"+NOR,users());
   foxp=new(__DIR__"fox");
   foxp->move(environment(this_object())); 
   npc->move(environment(this_object()));  
   npc->receive_damage("hp",12000); 
   npc->command("say 九尾妖狐！還不速速回塔！老僧就替天行道••大開殺戒！\n",me);
   npc->kill_ob(foxp);  
   foxp->command("say 嘿嘿嘿•••老頭••你以為本妖還是以前的我嘛！來吧！\n",me);
   foxp->kill_ob(npc);
    } 
    call_out("stop_altaraged",1800,this_object());  
    //call_out("JUMP_DOWN_RS",5);  
   // call_out("B_SD",60);
    return; 
}  
void stop_altaraged()
{
     this_object()->delete_temp("altaraged");
     return;
}   
/************************************************
void JUMP_DOWN_RS()
{
     object foxp;  
     if(objectp(foxp = present("evil fox",this_object())));
     message("world:world1:vision",HIM"\n\t九尾"+HIW"妖狐"+NOR"一躍而下，跳下了凌雲頂峰••\n\n"
                                   HIW"\n\t妙見和尚嘆道：唉∼此乃世人之大劫啊！老僧••••\n"
                                   HIW"\n\t              無能為力呀••只能死守納元塔罷了！\n\n"+NOR,users());   
     foxp->move(RS_EN); 
     return;
} 
**************************************************/ 
/********************************************************************
void B_SD()
{
     object bonzep;
     if(objectp(bonzep = present("miao-jian bonze",this_object())));
     bonzep->command("go southdown");
     return;
} 
**********************************************************************/

