#include <ansi.h>
inherit ITEM;

void open_war(object me,object ob);
void callzombie();
void end_war();
int query_zombie(); 
string *zombie=({"acheron_zombie","new_zombie","skeleton_zombie","shiver_zombie","hate_corpse",
"oascure_zombie"});

string *place=({"zk1","zk2","zk3","zk4","zk5","zk6","zk7","zk8","zk9","zk10","zk11","zk12",
"zk13","zk14","zk15","zk16","zk17","zk18","zk19","zk20","zk21","zk22","zk23"});

void create()
{
        set_name(WHT"封邪  古碑"NOR,({"fong-evil gravestone","gravestone"}) );
        set_weight(200000);
        set("long",@LONG

這是一座十分古老的石碑，上面的刻痕已難再辨識，看來建立的時間已經極久。
石碑上的碑文大略為︰【百年陰屍作亂，群英奮戰，封於遺跡其下，後輩能人，
以存四魄之玉啟之，使其現之，即可滅之，此事惟艱甚矣。 】
石碑上面似乎可以放些什麼東西(putting)

LONG);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","座");
                set("no_get",1);
                set("no_sac",1);
                set("value", 20000);
        }
        setup();
}

void init()
{
        add_action("do_putting","putting");
}

int do_putting(string arg)
{
        object me,ob,zombie,jade;
        me=this_player();
        ob=this_object();
        if(!arg || arg!="jade in gravestone") 
                return notify_fail("你要放什麼東西?(putting xxx in xxx)\n");
        if(!objectp(jade=present("four-soul jade",me) ) )
                return notify_fail("你身上沒有適合聚集陰氣的東西。\n");
        if( ob->query("open_war") || query_zombie() )
                return notify_fail("亂葬岡已經陰門大開了。\n");

        destruct(jade);
        message_vision("$N將四魂之玉放上石碑上。\n",me);
        message_vision(HIC"\n石碑上的碑文忽然發亮極為刺目...\n"NOR,me);
        ob->set("open_war",1);
        call_out("open_war",3,me,ob);
        return 1;
}

void open_war(object me,object ob)
{
        int i;        
        object g;

        if( !ob->query("open_war") ) return;
message("world:world1:vision",
HIY"\n    "+me->query("name") +HIR"釋放了陰脈的能量，封邪遺跡周圍忽然陰氣大盛.......\n\n"
HIW"        一隻隻百年陰屍忽然從亂葬岡深處破土而出.....\n\n\n"
HIB"整個亂葬岡登時陰風陣陣，屍橫遍野！！\n\n" NOR,users());           
          for(i=0;i<=12;i++)
        {
                g=new(__DIR__+"npc/"+zombie[random(sizeof(zombie) ) ] );
                g->move(__DIR__+place[random(sizeof(place))] );
        }

        call_out("callzombie",20);
        return;
}

void callzombie()
{
        object g;
        int i;
        //殭屍王        
        g=new(__DIR__"npc/zombieking");
        g->move(__DIR__"zk12");
        //屍將
        g=new(__DIR__"npc/one_zombie");
        g->move(__DIR__"zk12");
        
        g=new(__DIR__"npc/corpse_demon");
        g->move(__DIR__"zk17");
        
        g=new(__DIR__"npc/corpse_demon");
        g->move(__DIR__"zk4");
        
        g=new(__DIR__"npc/lost_zombie");
        g->move(__DIR__"zk7");
        
        g=new(__DIR__"npc/lost_zombie");
        g->move(__DIR__"zk9");
        
        g=new(__DIR__"npc/barbaric_zombie");
        g->move(__DIR__"zk1");
        
        g=new(__DIR__"npc/barbaric_zombie");
        g->move(__DIR__"zk13");    
     
     call_out("end_war",180);
     return;
}

void end_war()
{
   object zombie;
      if( query_zombie() )
                call_out("end_war",30,0);
        else {  
           message("world:world1:vision",
HIW"\n\n                封邪遺跡的陰門關閉，陰氣緩緩消散...\n\n"NOR
HIG"盤據在遺跡周圍的群屍回歸塵土，整個亂葬岡再歸以往的安寧了.....\n\n"NOR
           ,users());                 
           this_object()->set("open_war",0);
           }       
        return;
}

int query_zombie()
{
   object zombie;

        while( objectp(zombie=find_living("zombie-war-mob")) )
        {
                if( !environment(zombie) )
                {
                        destruct(zombie);
                        zombie = 0;
                }
                else break;
        }

        if( objectp(zombie) ) return 1;
        else return 0;
}















