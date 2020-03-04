#include <ansi.h>
inherit ITEM;
inherit SSERVER;
void create()
{
        set_name("PK精靈",({ "pk system"}));
        set_weight(100);
        if( clonep() )
         set_default_object(__FILE__);
        else 
        {
         set("long","pk專用物品。\n");
         set("unit","個");
         set("value",0);
        } 
        setup();
}

void init()
{
      add_action("do_pksec","pksec");
      add_action("do_geteq","geteq");
      add_action("do_whereis","whereis");
      add_action("do_allbusy","allbusy");
      add_action("do_goaway","goaway");
      this_object()->set_temp("invis",1);
      if(!this_player()->query("is_me_can_pk"))
      destruct(this_object());
}   

int do_geteq(string arg)
{
 object me,ob;
 string lit="";
 me=this_player();
 if(!arg)
 return notify_fail("geteq xxx\n");
 if(arg=="list")
 { 
         lit+="/open/world1/wilfred/sand/npc/eq/eq9\n";
         lit+="/open/world1/eq/sl_mask\n";
         lit+="/open/world1/eq/viper_cloth\n"; 
         lit+="/open/world1/eq/gs_waist\n";
         lit+="/open/world1/eq/bs_hands\n";
         lit+="/open/world1/eq/bt_neck\n";
         lit+="/open/world1/eq/gr_ring\n";
         lit+="/open/world1/eq/bc_cloak\n";
         lit+="/open/world1/acme/area/npc/obj/pearl\n";
         lit+="/open/world1/eq/clam_shield\n";
         lit+="/open/world1/wilfred/sand/npc/eq/eq7\n";
         lit+="/open/world1/ksj/east_island/npc/eq/kilin-boots\n";
         lit+="/open/world1/sdo/nonhero/obj/npc/eq/hero_leggings\n";         lit+="/open/world1/eq/ys_helmet4\n";         lit+="/open/world1/moonhide/pool/npc/obj/chi-lin-armor\n";
         write(lit);
         return 1; 
 } 
 ob=new(arg);
 if(ob->move(me))
 write("ok");
 else return notify_fail("something worng\n");
 return 1;
}

int do_whereis(string str)
{
        object ob, where, *ob_list,me;
        int i;
        if (!str)
                return notify_fail("指令格式﹕whereis <人物或檔名>\n"); 
        ob = find_player(str);
        me = this_player();
        if( !ob ) ob = find_living(str);
        if( !ob ) {
                str = resolve_path(me->query("cwd"), str);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        if( !ob = environment(ob_list[i]) ) continue;
                        printf("%O\n", ob );
                }
        }
        if (!ob) return notify_fail("現在沒這個人.\n");
        where = environment(ob);
        if (!where) return notify_fail("這個人不知道在那裡耶...\n");
        printf("--------------- %s現在在 ---------------\n",
                (string)ob->name());
        "/cmds/std/look"->look_room(me, where, 1);
        return 1;
}

int do_pksec(string str)
{
     object user;
     user = this_player();    
     if (str=="open")     {
      call_out("del_delay",0,user);
      write("pk系統開啟!...關閉請用pksec close\n");
      return 1;
     }  
     if (str=="close")
     {
      remove_call_out("del_delay");
      write("pk系統關閉!...開啟請用pksec open\n");
      return 1;
     }
}

void del_delay(string me)
{
  if( me->is_fighting())
  {
   me->add_busy(-10);
   write("PK精靈:busy is delete\n");
  }
  call_out("del_delay",1,me);
  return;
}

int do_allbusy(string str)
{
  object *attack_targets,me;
  int g,busy;
  me=this_player();
  if(!str||sscanf(str,"to %d",busy)!=1)  busy=1;
  attack_targets = me->query_enemy();
  for(g=0;g<sizeof(attack_targets);g++)
  {
   attack_targets[g]->start_busy(busy);
  }
  write("PK精靈:all emeny is busy"+busy+"回合\n");  return 1;
}

int do_goaway(mixed arg)
{
 object me;
 string str="";
 me=this_player();
 if(!arg || arg=="list")
 {
  str+="可以移動的區域有------\n";
  str+="第1區:天城附近的山路\n"; 
  str+="第2區:步靈城盜賊工會\n";
  str+="第3區:無沙鎮的造船場\n";
  str+="第4區:十萬大山的山中\n";
  str+="第5區:紫陽山上的山路\n";
  str+="第6區:凌雲寺附近山路\n";
  str+="第7區:疾風門的小花園\n";  
  str+="第8區:寒日洞的第二層\n";
  str+="第9區:鑄劍谷中的山路\n";
  str+="感謝您愛用本系統------\n";  
  write(str);
  return 1;
 } 
switch(arg)
 {
  case "1" : me->move("/open/world1/acme/area/pass4");
             break;
  case "2" : me->move("/open/world1/ksj/thief/room2");
             break;
  case "3" : me->move("/open/world1/wu_sha_town/seacoun35");
             break;
  case "4" : me->move("/open/world1/faceoff/sky/ten37");
             break;
  case "5" : me->move("/open/world1/cominging/purple_sun/1f2");
             break;
  case "6" : me->move("/open/world1/tmr/advbonze/hill3");
             break;
  case "7" : me->move("/open/world1/cominging/area/flurry11");
             break;
  case "8" : me->move("/open/world1/tmr/bagi/area/2f/map_7_6");
             break;
  case "9" : me->move("/open/world1/acme/bonze/b4");
             break;
}
me->set_temp("hide",10);
write("PK精靈:你成功\到達"+arg+"區了,並且hide了\n");
return 1;
}

